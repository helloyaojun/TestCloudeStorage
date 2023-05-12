//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import <HMFoundation/HMFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGCStorageTask<__covariant TResult> : NSObject

/// 任务是否结束
@property(nonatomic, readonly) BOOL isComplete;

/// 任务是否成功
@property(nonatomic, readonly) BOOL isSuccessful;

/// 任务是否已取消
@property(nonatomic, readonly) BOOL isCanceled;

/// 任务成功的结果
@property(nonatomic, nullable, readonly) TResult result;

/// 任务失败的错误
@property(nonatomic, nullable, readonly) NSError *error;

/// 任务过程中的状态
@property(nonatomic, nullable, readonly) TResult timePointState;

/// 任务是否暂停
@property(nonatomic, readonly) BOOL isPaused;

/// 任务是否进行中
@property(nonatomic, readonly) BOOL isInProgress;

/// 取消当前任务
- (BOOL)cancel;

/// 暂停当前任务
- (BOOL)pause;

/// 继续当前任务
- (BOOL)resume;

/// 添加任务进度的回调事件
/// @param progressCallback 进度的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnProgressCallback:(void (^)(TResult _Nullable result))progressCallback
    NS_SWIFT_NAME(onProgress(callback:));

/// 添加任务进度的回调事件
/// @param executor 回调事件执行的队列
/// @param progressCallback 进度的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnProgressAt:(id<HMFExecutor>)executor
                            callback:(void (^)(TResult _Nullable result))progressCallback
    NS_SWIFT_NAME(onProgress(at:callback:));

/// 添加任务暂停时触发的回调事件
/// @param pausedCallback 暂停的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnPausedCallback:(void (^)(TResult _Nullable result))pausedCallback
    NS_SWIFT_NAME(onPaused(callback:));

/// 添加任务暂停时触发的回调事件
/// @param executor 回调事件执行的队列
/// @param pausedCallback 暂停的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnPausedAt:(id<HMFExecutor>)executor
                            callback:(void (^)(TResult _Nullable result))pausedCallback
    NS_SWIFT_NAME(onPaused(at:callback:));

/// 添加任务成功触发的回调事件
/// @param successCallback 成功的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnSuccessCallback:(void (^)(TResult _Nullable result))successCallback
    NS_SWIFT_NAME(onSuccess(callback:));

/// 添加任务成功触发的回调事件
/// @param executor 回调事件执行的队列
/// @param successCallback 成功的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnSuccessAt:(id<HMFExecutor>)executor
                            callback:(void (^)(TResult _Nullable result))successCallback
    NS_SWIFT_NAME(onSuccess(at:callback:));

/// 添加任务失败触发的回调事件
/// @param failureCallback 失败的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnFailureCallback:(void (^)(NSError *error))failureCallback
    NS_SWIFT_NAME(onFailure(callback:));

/// 添加任务失败触发的回调事件
/// @param executor 回调事件执行的队列
/// @param failureCallback 失败的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnFailureAt:(id<HMFExecutor>)executor
                            callback:(void (^)(NSError *error))failureCallback
    NS_SWIFT_NAME(onFailure(at:callback:));

/// 添加任务完成触发的回调事件，无论成功失败都会触发
/// @param completeCallback 完成的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnCompleteCallback:(void (^)(AGCStorageTask<TResult> *task))completeCallback
    NS_SWIFT_NAME(onComplete(callback:));

/// 添加任务完成触发的回调事件，无论成功失败都会触发
/// @param executor 回调事件执行的队列
/// @param completeCallback 完成的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnCompleteAt:(id<HMFExecutor>)executor
                             callback:(void (^)(AGCStorageTask<TResult> *task))completeCallback
    NS_SWIFT_NAME(onComplete(at:callback:));

/// 添加当任务取消时触发的回调事件
/// @param cancelCallback 取消的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnCanceledCallback:(void (^)(void))cancelCallback
    NS_SWIFT_NAME(onCancel(callback:));

/// 添加当任务取消时触发的回调事件
/// @param executor 回调事件执行的队列
/// @param cancelCallback 取消的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)addOnCanceledAt:(id<HMFExecutor>)executor
                             callback:(void (^)(void))cancelCallback
    NS_SWIFT_NAME(onCancel(at:callback:));

/// 移除任务进度的回调事件
/// @param progressCallback 进度的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnProgressCallback:(void (^)(TResult _Nullable result))progressCallback
    NS_SWIFT_NAME(removeOnProgress(callback:));

/// 移除任务暂停时触发的回调事件
/// @param pausedCallback 暂停的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnPausedCallback:(void (^)(TResult _Nullable result))pausedCallback
    NS_SWIFT_NAME(removeOnPaused(callback:));

/// 移除任务成功触发的回调事件
/// @param successCallback 成功的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnSuccessCallback:(void (^)(TResult _Nullable result))successCallback
    NS_SWIFT_NAME(removeOnSuccess(callback:));

/// 移除任务失败触发的回调事件
/// @param failureCallback 失败的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnFailureCallback:(void (^)(NSError *error))failureCallback
    NS_SWIFT_NAME(removeOnFailure(callback:));

/// 移除任务完成触发的回调事件，无论成功失败都会触发
/// @param completeCallback 完成的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnCompleteCallback:(void (^)(AGCStorageTask<TResult> *task))completeCallback
    NS_SWIFT_NAME(removeOnComplete(callback:));

/// 移除当任务取消时触发的回调事件
/// @param cancelCallback 取消的回调
/// @result 当前任务
- (AGCStorageTask<TResult> *)removeOnCanceledCallback:(void (^)(void))cancelCallback
    NS_SWIFT_NAME(removeOnCancel(callback:));

@end



/// 用于开发者自定义任务
/// TResult 任务执行成功返回的数据类型
NS_SWIFT_NAME(StorageTaskCompletionSource)
@interface AGCStorageTaskCompletionSource<__covariant TResult> : NSObject

- (void)setTimePointState:(TResult _Nullable)progress;

/// 设置任务执行成功
/// @param result 任务执行的结果
- (void)setResult:(TResult _Nullable)result;

/// 设置任务执行失败
/// @param error 任务失败的错误
- (void)setError:(NSError *)error;

/// 设置任务取消的回调
/// @param cancelHandler 任务取消的回调
- (void)setCancelHandler:(void(^)(void))cancelHandler;

/// 设置任务暂停的回调
/// @param pauseHandler 任务暂停的回调
- (void)setPauseHandler:(void(^)(void))pauseHandler;

/// 设置任务继续的回调
/// @param resumeHandler 任务继续的回调
- (void)setResumeHandler:(void(^)(void))resumeHandler;

/// 返回异步任务
- (AGCStorageTask<TResult> *)getTask;

@end


NS_ASSUME_NONNULL_END
