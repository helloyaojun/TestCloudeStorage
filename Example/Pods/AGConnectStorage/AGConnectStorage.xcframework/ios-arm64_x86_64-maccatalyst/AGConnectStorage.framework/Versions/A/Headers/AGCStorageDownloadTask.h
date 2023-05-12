//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import "AGCStorageTask.h"
@class AGCStorageDownloadTask;
@class AGCStorageReference;

NS_ASSUME_NONNULL_BEGIN

@interface AGCStorageDownloadResult : NSObject

@property(nonatomic, readonly, weak) AGCStorageDownloadTask *task;

@property(nonatomic, readonly, weak) AGCStorageReference *storageReference;

@property(nonatomic, readonly, nullable) NSError *error;

@property(nonatomic, readonly) int64_t bytesTransferred;

@property(nonatomic, readonly) int64_t totalByteCount;

@end

@interface AGCStorageDownloadTask : AGCStorageTask <AGCStorageDownloadResult *>

@end

NS_ASSUME_NONNULL_END
