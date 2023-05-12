//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
@class AGCStorageReference;

NS_ASSUME_NONNULL_BEGIN

@interface AGCStorageListResult : NSObject

/// storage reference文件类型列表
@property(nonatomic,readonly)NSArray<AGCStorageReference *> *fileList;

/// storage reference文件夹类型列表
@property(nonatomic,readonly)NSArray<AGCStorageReference *> *dirList;

/// 下一次循环的游标
@property(nonatomic,readonly)NSString *pageMarker;

@end

NS_ASSUME_NONNULL_END
