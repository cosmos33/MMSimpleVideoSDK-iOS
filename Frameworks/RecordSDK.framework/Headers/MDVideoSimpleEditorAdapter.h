//
//  MDVideoSimpleEditorAdapter.h
//  MMVideoSDK
//
//  Created by MOMO on 2019/7/4.
//

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import "MDCancellable.h"

//@protocol MLTimeRangeMappingEffect;

NS_ASSUME_NONNULL_BEGIN

@interface MDVideoSimpleEditorAdapter : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithToken:(NSString *)token;

// 加载视频
- (void)loadVideo:(AVAsset *)asset;
- (void)setVideoTimeRange:(CMTimeRange)timeRange;
- (void)setPitchShiftURL:(NSURL *)url;
//- (void)setTimeRangeMappingEffects:(NSArray<id<MLTimeRangeMappingEffect>> *)timeRangeMappingEffects;
- (void)setMediaSourceRepeatRange:(CMTimeRange)timeRange;

// 默认为NO，当置为YES时候，调用 `loadVideo` 方法会自动调用 `compositeVideoWithError:`方法合成视频
@property (nonatomic, assign) BOOL autoComposite;

@property (nonatomic, strong, nullable) NSURL *backgroundAudioURL;
@property (nonatomic, assign) CMTimeRange backgroundAudioRange;

- (void)setSourceVolume:(float)volume;
- (void)setBackgroundMusicVolume:(float)volume;

- (BOOL)compositeVideoWithError:(NSError * _Nullable * _Nullable)error;
- (void)updateAudioMix;

// 播放器控制
- (void)play;
- (void)stop;
- (void)pause;
- (void)replay;

@property (nonatomic, readonly) UIViewController *playerViewController;
@property (nonatomic, readonly) AVPlayer *player;
@property (nonatomic, readonly) BOOL isPlaying;

- (void)seekTime:(CMTime)time;
- (NSTimeInterval)duration;
- (CMTime)getCurrentPlayTime;
- (void)setPlayerPerferredFPS:(int)fps;

@property (nonatomic, readonly) CGRect videoRenderFrame;
@property (nonatomic, readonly) AVComposition *composition;

- (void)waitUntilAllOperationsAreFinished;

@property (nonatomic, copy) void(^ _Nullable playToEndTime)(AVPlayer *player);
@property (nonatomic, copy) void(^ _Nullable playerPeriodicTimeCallback)(CMTime time);

@end

@interface MDVideoSimpleEditorAdapter (Export)

@property (nonatomic, assign) float targetBitRate;
@property (nonatomic, assign) CGSize presentationSize;
@property (nonatomic, assign) NSInteger targetFrameRate;
@property (nonatomic, assign) CGAffineTransform videoPerferredTransform;

- (id<MDCancellable>)exportToURL:(NSURL *)url
                 progressHandler:(void(^ _Nullable)(double progress))progressHandler
                      completion:(void(^ _Nullable)(NSURL *url))completion
                         failure:(void(^ _Nullable)(NSError * _Nullable error))failure;

@end

NS_ASSUME_NONNULL_END
