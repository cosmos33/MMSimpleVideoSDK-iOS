//
//  MDRecordingSimpleAdapter.h
//  MMVideoSDK
//
//  Created by MOMO on 2019/7/2.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MDRecordCameraAdapter.h"

@protocol MLPixelBufferDisplay;

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordingSimpleAdapter : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithToken:(NSString *)token;

@property (nonatomic, strong, readonly) UIView<MLPixelBufferDisplay> *previewView;

@end

@interface MDRecordingSimpleAdapter (Capture)

- (void)setMaxRecordDuration:(NSTimeInterval)duration;
- (void)setMinRecordDuration:(NSTimeInterval)duration;

- (void)setVideoCodecKey:(NSString *)codeckey;
- (void)setVideoBitRate:(float)bitrate;
- (void)setVideoFrameRate:(NSInteger)frameRate;

- (void)setVideoResolution:(CGSize)resolution;
- (void)setVideoScaleMode:(NSString *)scaleMode;

- (void)setCameraPreset:(AVCaptureSessionPreset)preset;
- (void)setCameraPosition:(AVCaptureDevicePosition)position;
- (void)setCameraFrameRate:(NSInteger)frameRate;

- (void)setupRecorder;

- (void)setVideoZoomFactor:(CGFloat)factor;
- (CGFloat)videoZoomFactor;

- (NSTimeInterval)recordDuration;

// 是否支持闪光灯
- (BOOL)hasFlash;

// 闪光灯模式
- (NSArray *)supportFlashModes;

// 设置闪光灯模式
@property (nonatomic, assign) MDRecordCaptureFlashMode flashMode;

- (BOOL)hasVideoInput;

@property (nonatomic, assign, readonly) AVCaptureDevicePosition cameraPosition;

- (void)switchCameraPosition;
- (void)focusCameraInPoint:(CGPoint)pointInCamera;
- (void)expposureInPoint:(CGPoint)pointInCamera;
- (void)startCapturing;
- (void)pauseCapturing;
- (void)stopCapturing;

- (void)enableAudioRecording:(BOOL)enable;

@property (nonatomic, assign) BOOL shouldRecordAudio;

- (void)switchToCameraSourceType:(MDRecordCameraSourceType)cameraSourceType;
- (MDRecordCameraSourceType)cameraSourceType;

- (void)takePhoto;
// 即将开始拍照
@property (nonatomic, copy) void (^captureStillImageWillHandler)(void);
// 拍照结果回调
@property (nonatomic, copy) void (^captureStillImageHandler)(UIImage *image, NSDictionary *metaInfo);

@property (nonatomic, assign)           UIDeviceOrientation     outputOrientation;

@property (nonatomic, copy, nullable) void(^cameraDidOutputVideoSampleBuffer)(CMSampleBufferRef sampleBuffer);
@property (nonatomic, copy, nullable) void(^cameraDidOutputAudioSampleBuffer)(CMSampleBufferRef sampleBuffer);

@end

@interface MDRecordingSimpleAdapter (Recording)

@property (nonatomic, assign) BOOL saveOrigin;

- (BOOL)canStartRecording;
- (void)startRecording;
- (void)pauseRecording;
- (void)cancelRecording;
- (void)stopVideoCaptureWithOutputURL:(NSURL *)URL
                    completionHandler:(void (^)(NSURL *videoFileURL, NSError *error))completionHandler;
- (NSInteger)savedSegmentCount;

- (void)deleteLastSavedSegment;
- (void)resetRecorder;

- (void)cleanStashFile;

@property (nonatomic, readonly) BOOL isRecording;
@property (nonatomic, readonly) NSTimeInterval currentRecordingDuration;
@property (nonatomic, readonly) NSTimeInterval currentRecordingPresentDuration;
@property (nonatomic, assign, readonly) BOOL                    stopMerge;
@property (nonatomic, strong, readonly) id                      periodicTimeObserver;//配乐播放开始观察者

@property (nonatomic, copy) void (^recordProgressChangedHandler)(double progress);
@property (nonatomic, copy) void (^recordDurationReachedHandler)(void);
@property (nonatomic, copy) void (^completeProgressUpdateHandler)(double progress);
@property (nonatomic,copy) void (^recordSegmentsChangedHandler)(NSArray *durations, NSArray *presentDurations, BOOL valid);

@end

@interface MDRecordingSimpleAdapter (Music)

// 音乐资源
@property (nonatomic, strong, nullable) AVAsset *backgroundAudio;

@end

@interface MDRecordingSimpleAdapter (SpeedVary)

- (void)setNextRecordSegmentSpeedVaryFactor:(CGFloat)factor;
- (CGFloat)nextRecordSegmentSpeedVaryFactor;
- (void)speedVaryShouldAllow:(BOOL)isAllow;
- (BOOL)hasPerSpeedEffect;

@end

NS_ASSUME_NONNULL_END
