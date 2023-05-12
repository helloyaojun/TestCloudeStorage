//
//  ViewController.swift
//  TestCloudeStorage
//
//  Created by yaojun on 05/06/2023.
//  Copyright (c) 2023 yaojun. All rights reserved.
//

import UIKit
import TestCloudeStorage
import AGConnectCore

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        AGCInstance.startUp()

        // Do any additional setup after loading the view, typically from a nib.
        let storageManager = CloudeStorageManager.shared
//        storageManager.loginAnonymously { user, error in
//            storageManager.uploadFile(fileName: "test.jpg") { url, error in
//                print(url)
//                print(error)
//            }
//        }

        let dirPath = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true).first;
        let filePath = dirPath!.appending("/test.jpg")
        let data = FileManager.default.contents(atPath: filePath)
//        storageManager.uploadFileData(data: data!) { url, error in
//            print(url)
//            print(error)
//        }

//        storageManager.downloadFile(fileName: "test.jpg") { path, error in
//            print(path)
//            print(error)
//        }
        storageManager.deleteFile(fileName: "test.jpg") { error in
            print(error)
        }
        storageManager.getFileList(count: 20) { filelist, dirlist, error in
            //
            print(filelist)
            print(dirlist)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

