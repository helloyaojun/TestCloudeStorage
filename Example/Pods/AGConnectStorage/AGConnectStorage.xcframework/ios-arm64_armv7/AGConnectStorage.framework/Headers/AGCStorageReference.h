//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import "AGCStorageUploadTask.h"
#import "AGCStorageDownloadTask.h"
#import "AGCStorageMetadata.h"
#import "AGCStorageListResult.h"
@class AGCStorage;

NS_ASSUME_NONNULL_BEGIN

///  Represents a reference to a AGC Cloud Storage object
@interface AGCStorageReference : NSObject

/// the storage
@property(nonatomic,readonly)AGCStorage *storage;

/// the bucket name
@property(nonatomic,readonly)NSString *bucketName;

/// the object path
@property(nonatomic,readonly)NSString *path;

/// the object name
@property(nonatomic,readonly)NSString *name;

/// Child storage reference
/// @param path the object path
/// @return the storage reference
- (AGCStorageReference *)child:(NSString *)path;

/// Get parent
/// @return the storage reference
- (AGCStorageReference *)parent;

/// Get root
/// @return the storage reference
- (AGCStorageReference *)root;

/// Compare the string representation of this reference with that of another
/// @param otherReference the other reference
/// @return result
- (BOOL)isEqualTo:(AGCStorageReference *)otherReference;

#pragma mark - upload

/// Upload task for data
/// @param data bytes been uploaded
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadData:(NSData *)data;

/// Upload task for data
/// @param data bytes been uploaded
/// @param metadata the metadata
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadData:(NSData *)data metadata:(AGCStorageMetadata *_Nullable)metadata;

/// Upload task for data
/// @param data bytes been uploaded
/// @param metadata the metadata
/// @param offset the offset
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadData:(NSData *)data metadata:(AGCStorageMetadata *_Nullable)metadata offset:(int64_t)offset;

/// Upload task for file
/// @param fileURL file been uploaded
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadFile:(NSURL *)fileURL;

/// Upload task for file
/// @param fileURL file been uploaded
/// @param metadata the metadata
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadFile:(NSURL *)fileURL metadata:(AGCStorageMetadata *_Nullable)metadata;

/// Upload task for file
/// @param fileURL file been uploaded
/// @param metadata the metadata
/// @param offset the offset
/// @return the task
- (AGCStorageUploadTask *_Nullable)uploadFile:(NSURL *)fileURL metadata:(AGCStorageMetadata *_Nullable)metadata offset:(int64_t)offset;

#pragma mark - download

/// Download task for file
/// @param destFileURL the target file url
/// @return the task
- (AGCStorageDownloadTask *_Nullable)downloadToFile:(NSURL *)destFileURL;

/// Download task for data
/// @param size the maximum allowed size in bytes that will be allocated
/// @return the tas
- (HMFTask<NSData *> *_Nullable)downloadDataWithMaxSize:(int64_t)size;

/// Get download url
/// @return the task
- (HMFTask<NSURL *> *)getDownloadUrl;

#pragma mark - delete

/// Delete file
/// @return the task
- (HMFTask *)deleteFile;

#pragma mark - metadata

/// Get file metadata
/// @return the task
- (HMFTask<AGCStorageMetadata *> *)getMetadata;

/// Update file metadata
/// @return the task
- (HMFTask<AGCStorageMetadata *> *)updateMetadata:(AGCStorageMetadata *)metadata;

#pragma mark - list

/// List task
/// @param max the maximum size of list
/// @return the task
- (HMFTask<AGCStorageListResult *> *)list:(NSInteger)max;

/// List task
/// @param max the maximum size of list
/// @param marker the marker
/// @return the task
- (HMFTask<AGCStorageListResult *> *)list:(NSInteger)max marker:(NSString *)marker;

/// List all task
/// @return the task
- (HMFTask<AGCStorageListResult *> *)listAll;

#pragma mark - active tasks

/// Get the set of active upload tasks currently in progress
/// @return the task array
- (NSArray<AGCStorageUploadTask *> *)activeUploadTasks;

/// Get the set of active download tasks currently in progress
/// @return the task array
- (NSArray<AGCStorageDownloadTask *> *)activeDownloadTasks;

@end

NS_ASSUME_NONNULL_END
