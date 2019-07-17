//
//  MDImageSimpleEditorAdapter.h
//  MMVideoSDK
//
//  Created by MOMO on 2019/7/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDImageSimpleEditorAdapter : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithToken:(NSString *)token;

// 初始化
- (void)loadImage:(UIImage *)image completionHander:(void(^)(CVPixelBufferRef _Nullable, NSError * _Nullable))completion;

- (void)reloadImage:(UIImage *)image;

// 流程
- (void)startProcess;
- (void)stopProcess;

@end

NS_ASSUME_NONNULL_END
