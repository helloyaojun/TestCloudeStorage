//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import "AGCStorageTask.h"
@class AGCStorageMetadata;
@class AGCStorageUploadTask;
@class AGCStorageReference;

NS_ASSUME_NONNULL_BEGIN

@interface AGCStorageUploadResult : NSObject

@property(nonatomic, readonly, weak) AGCStorageUploadTask *task;

@property(nonatomic, readonly, weak) AGCStorageReference *storageReference;

@property(nonatomic, readonly, nullable) NSError *error;

@property(nonatomic, readonly) int64_t bytesTransferred;

@property(nonatomic, readonly) int64_t totalByteCount;

@property(nonatomic, readonly) AGCStorageMetadata *metadata;

@end

@interface AGCStorageUploadTask : AGCStorageTask <AGCStorageUploadResult *>

@end

NS_ASSUME_NONNULL_END
