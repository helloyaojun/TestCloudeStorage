//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// storage error code
typedef NS_ENUM(NSUInteger, AGCStorageErrorCode) {
    AGCStorageErrorCodeIllegalArguments = 1,
    AGCStorageErrorCodeUnknown = 11001,
    AGCStorageErrorCodeProjectNotFound = 11002,
    AGCStorageErrorCodeBucketNotFound = 11003,
    AGCStorageErrorCodeObjectNotFound = 11004,
    AGCStorageErrorCodeQuotaExceeded = 11005,
    AGCStorageErrorCodeNotAuthenticated = 11006,
    AGCStorageErrorCodeNotPermission = 11007,
    AGCStorageErrorCodeOperationFrequent = 11008,
    AGCStorageErrorCodeInvalidHashVerify = 11009,
    AGCStorageErrorCodeCanceled = 11010,
    AGCStorageErrorCodeRequestTimeout = 11011,
    AGCStorageErrorCodeFileAccess = 11012,
    AGCStorageErrorCodeServerRspInvalid = 11013,
    AGCStorageErrorCodeMetaShaEmpty = 11014,
    AGCStorageErrorCodeNetworkUnavailable = 11015,
    AGCStorageErrorCodeRangeUnsatisfiable = 11016,
};

@interface AGCStorageError : NSError


@end

NS_ASSUME_NONNULL_END
