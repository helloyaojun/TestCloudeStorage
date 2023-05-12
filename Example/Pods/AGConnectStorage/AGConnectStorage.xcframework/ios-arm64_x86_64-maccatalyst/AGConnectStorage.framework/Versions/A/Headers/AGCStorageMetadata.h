//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
@class AGCStorageReference;

NS_ASSUME_NONNULL_BEGIN

@interface AGCStorageMetadata : NSObject

@property(nonatomic, weak) AGCStorageReference *storageReference;

@property(nonatomic) NSString *bucketName;

@property(nonatomic) NSString *path;

@property(nonatomic, readonly, nullable) NSString *name;

@property(nonatomic, readonly, nullable) NSString *createTime;

@property(nonatomic, readonly, nullable) NSString *modifyTime;

@property(nonatomic, readonly) int64_t size;

@property(nonatomic, nullable) NSString *sha256Hash;

@property(nonatomic, nullable) NSString *contentType;

@property(nonatomic, nullable) NSString *cacheControl;

@property(nonatomic, nullable) NSString *contentDisposition;

@property(nonatomic, nullable) NSString *contentEncoding;

@property(nonatomic, nullable) NSString *contentLanguage;

@property(nonatomic, nullable) NSDictionary<NSString *, NSString *> *customMetadata;

@end

NS_ASSUME_NONNULL_END
