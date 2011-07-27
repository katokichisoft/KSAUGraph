//
//  KSAUGraphManager.h
//  KSAUGraph
//
//  Created by 加藤 寛人 on 11/07/26.
//  Copyright 2011 KatokichiSoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioUnit/AudioUnit.h>
#import "iPhoneCoreAudio.h"

@interface KSAUGraphManager : NSObject {
    BOOL isPlaying_;
    AUGraph auGraph_;
    AudioUnit multiChannelMixerAudioUnit_;

    NSArray *channels_;
}

+ (id)sharedInstance;

// オーディオ出力の準備
// arrayには各チャネルを定義したクラスを入れておく（最大８個）
- (void)prepareWithChannels:(NSArray *)array;

// 動作開始/停止
-(void)play;
-(void)stop;

// 全体のボリュームを設定(0.0〜1.0)
- (void)setVolume:(Float32)volume;
@end
