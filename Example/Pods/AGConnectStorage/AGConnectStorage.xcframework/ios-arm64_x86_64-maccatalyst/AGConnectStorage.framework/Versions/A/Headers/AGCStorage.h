//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import "AGCStorageReference.h"
#import <AGConnectCore/AGConnectCore.h>

NS_ASSUME_NONNULL_BEGIN

/// 云存储服务入口类
@interface AGCStorage : NSObject

@property(nonatomic, assign) NSTimeInterval maxUploadTimeout;

@property(nonatomic, assign) NSTimeInterval maxDownloadTimeout;

@property(nonatomic, assign) NSTimeInterval maxRequestTimeout;

@property(nonatomic, assign) NSInteger      retryTimes;

/// Get instance
/// @return the instance
+ (instancetype)getInstance;

/// Get instance
/// @param app the instance
/// @return the instance
+ (instancetype)getInstance:(AGCInstance *)app;

/// Get instance
/// @param bucketName the bucket name
/// @return the instance
+ (instancetype)getInstanceForBucketName:(NSString *)bucketName;

/// Get instance
/// @param app the instance
/// @param bucketName the bucket name
/// @return the instance
+ (instancetype)getInstance:(AGCInstance *)app bucketName:(NSString *)bucketName;

/// Get reference
/// @return the reference
- (AGCStorageReference *)reference;

/// Get reference
/// @param objectPath the object path
/// @return the reference
- (AGCStorageReference *)referenceWithPath:(NSString *)objectPath;

/// Get reference
/// @param url the reference url
/// @return the reference
- (AGCStorageReference *)referenceFromUrl:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
