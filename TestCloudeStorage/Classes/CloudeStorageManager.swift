//
//  CloudeStorageManager.swift
//  TestCloudeStorage
//
//  Created by iss730001004790 on 2023/5/6.
//

import UIKit
import AGConnectStorage
import AGConnectAuth

class CloudeStorageConfiger: NSObject {

    var bucketName: String?
    var localUploadFilePath: String?
    var cloudeFilePath: String?
    private(set) var defaultlocalUploadFilePath: String?
    private(set) var defaultCloudeFilePath: String?

}

@objcMembers
open class CloudeStorageManager: NSObject {

    public static let shared = CloudeStorageManager()

    var storage : AGCStorage? = AGCStorage.getInstance()
    public var bucketName: String!{
        willSet {
            storage = AGCStorage.getInstanceForBucketName(newValue)
        }
    }
    var localUploadFilePath: String?
    var localDownloadFilePath: String?
    var cloudeFilePath: String?
    let defaultlocalUploadFilePath: String = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true).first!
    let defaultlocalDownloadFilePath: String = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true).first!
    let defaultCloudeFilePath: String = ""

    override init() {


    }
    public func loginAnonymously(callback: @escaping((_ user: AGCUser?, _ error: NSError?) -> Void)) {
        DispatchQueue.global().async {
            AGCAuth.instance().signInAnonymously().onSuccess { (result) in
                DispatchQueue.main.async {
                    callback(result?.user, nil)
                }
                print("login success")
            }.onFailure { (error) in
                DispatchQueue.main.async {
                    callback(nil, error as NSError)
                }
                print("login failed ",error)
            }
        }
    }

    public func uploadFile(fileName: String, callback: @escaping((_ downloadUrl: NSURL?, _ error: NSError?) -> Void)) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let cloudPath = cloudeFilePath ?? defaultCloudeFilePath
        let storageReference = storage?.reference(withPath: cloudPath + "/" + fileName)
        var filePath = localUploadFilePath ?? defaultlocalUploadFilePath
        filePath = filePath.appending("/" + fileName)

        DispatchQueue.global().async {
            let task = storageReference?.uploadFile(URL.init(fileURLWithPath: filePath))
            task?.onSuccess(callback: { (result) in
                storageReference?.getDownloadUrl().onSuccess(callback: { downloadUrl in
                    DispatchQueue.main.async {
                        callback(downloadUrl, nil)
                    }
                })
                print("upload success ",result ?? "")
            }).onComplete(callback: { (task) in
                print("upload complete ",task.result ?? "")
            }).onProgress(callback: { (result) in
                print("upload progress \(result?.bytesTransferred ?? 0), \(result?.totalByteCount ?? 0)")
            }).onPaused(callback: { (result) in
                print("upload paused")
            }).onCancel {
                print("upload canceled")
            }.onFailure(callback: { (error) in
                DispatchQueue.main.async {
                    callback(nil, error as NSError)
                }
                print("upload failed ",error)
            })

        }
    }

    public func uploadFileData(data: Data, suffix: String, callback: @escaping((_ downloadUrl: NSURL?, _ error: NSError?) -> Void)) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let cloudPath = cloudeFilePath ?? defaultCloudeFilePath
        let storageReference = storage?.reference(withPath: cloudPath + "/" + String(CLong(Date().timeIntervalSince1970 * 1000)) + suffix)

        DispatchQueue.global().async {
            let task = storageReference?.uploadData(data)
            task?.onSuccess(callback: { (result) in
                storageReference?.getDownloadUrl().onSuccess(callback: { downloadUrl in
                    DispatchQueue.main.async {
                        callback(downloadUrl, nil)
                    }
                })
                print("upload success ",result ?? "")
            }).onComplete(callback: { (task) in
                print("upload complete ",task.result ?? "")
            }).onProgress(callback: { (result) in
                print("upload progress \(result?.bytesTransferred ?? 0), \(result?.totalByteCount ?? 0)")
            }).onPaused(callback: { (result) in
                print("upload paused")
            }).onCancel {
                print("upload canceled")
            }.onFailure(callback: { (error) in
                DispatchQueue.main.async {
                    callback(nil, error as NSError)
                }
                print("upload failed ",error)
            })

        }
    }

    public func downloadFile(fileName: String, callback: @escaping((_ filePath: String?, _ error: NSError?) -> Void)) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let cloudPath = cloudeFilePath ?? defaultCloudeFilePath
        let storageReference = storage?.reference(withPath: cloudPath + "/" + fileName)
        var filePath = localDownloadFilePath ?? defaultlocalDownloadFilePath
        let tempPath = filePath.appending("/" + fileName)
        if (FileManager.default.fileExists(atPath: (tempPath))) {
            filePath = filePath.appending("/" + String(Date().timeIntervalSince1970) + "_" + fileName)
        }else {
            filePath = tempPath
        }

        DispatchQueue.global().async {
            let task = storageReference?.download(toFile: URL.init(fileURLWithPath: filePath))
            task?.onSuccess(callback: { (result) in
                DispatchQueue.main.async {
                    callback(filePath, nil)
                }
                print("download success ",result ?? "")
            }).onComplete(callback: { (task) in
                print("download complete ",task.result ?? "")
            }).onProgress(callback: { (result) in
                print("download progress \(result?.bytesTransferred ?? 0), \(result?.totalByteCount ?? 0)")
            }).onPaused(callback: { (result) in
                print("download paused")
            }).onCancel {
                print("download canceled")
            }.onFailure(callback: { (error) in
                DispatchQueue.main.async {
                    callback(nil, error as NSError)
                }
                print("download failed ",error)
            })
        }
    }

/*
    public func getFileMetadata(fileName: String) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let cloudPath = cloudeFilePath ?? defaultCloudeFilePath
        let storageReference = storage?.reference(withPath: cloudPath + "/" + fileName)
        let task = storageReference?.getMetadata()
        task?.onSuccess(callback: { (result) in
            print("getFileMetadata success ",result ?? "")
        }).onFailure(callback: { (error) in
            print("getFileMetadata failed ",error)
        })
    }
 */

    public func getFileList(count: Int, callback: @escaping((_ fileList: [AGCStorageReference]?, _ dirList: [AGCStorageReference]?, _ error: NSError?) -> Void)) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let storageReference = storage?.reference()
        DispatchQueue.global().async {
            let task = storageReference?.list(count)
            task?.onSuccess(callback: { (result) in
                DispatchQueue.main.async {
                    callback(result?.fileList, result?.dirList, nil)
                }
                print("getFileList success ",result ?? "")
            }).onFailure(callback: { (error) in
                DispatchQueue.main.async {
                    callback(nil, nil, error as NSError)
                }
                print("getFileList failed ",error)
            })
        }
    }

    public func deleteFile(fileName: String, callback: @escaping((_ error: NSError?) -> Void)) {
        assert(AGCAuth.instance().currentUser != nil, "AGC logged in user can operate")

        let cloudPath = cloudeFilePath ?? defaultCloudeFilePath
        let storageReference = storage?.reference(withPath: cloudPath + "/" + fileName)
        DispatchQueue.global().async {
            let task = storageReference?.deleteFile()
            task?.onSuccess(callback: { (result) in
                DispatchQueue.main.async {
                    callback(nil)
                }
                print("deleteFile success ",result ?? "")
            }).onFailure(callback: { (error) in
                DispatchQueue.main.async {
                    callback(error as NSError)
                }
                print("deleteFile failed ",error)
            })
        }
    }
}
