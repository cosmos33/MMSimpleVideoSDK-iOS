//
//  MDVideoAssetProcessBuilder.h
//  RecordSDK
//
//  Created by sunfei on 2018/12/14.
//  Copyright © 2018 sunfei. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "MDAssetPorcessBuilder.h"

#if __has_include("MDAssetScale.h")
@protocol MLTimeRangeMappingEffect;
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MDVideoAssetProcessBuilder : NSObject <MDAssetPorcessBuilder>

// use for builder asset process
@property (nonatomic, assign) CMTimeRange range;
@property (nonatomic, strong) NSURL *sourcePitchShiftURL;
@property (nonatomic, assign) CGAffineTransform videoPreferredTransform;
@property (nonatomic, assign) CMTimeRange mediaSourceRepeatRange;
#if __has_include("MDAssetScale.h")
@property (nonatomic, strong) NSArray<id<MLTimeRangeMappingEffect>> *timeRangeMappingEffects;
#endif
@property (nonatomic, strong) NSURL *backgroundMusicURL;
@property (nonatomic, assign) CMTimeRange backgroundMusicRange;

// use for build audiomix
@property (nonatomic, assign) CGFloat sourceVolume;
@property (nonatomic, assign) CGFloat backgroundMusicVolume;

@property (nonatomic, readonly) id audioSourceHint;

- (AVAudioMix *)buildAudioMix;

@end

NS_ASSUME_NONNULL_END
