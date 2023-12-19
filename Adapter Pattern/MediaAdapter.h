#ifndef MEDIAADAPTER_H
#define MEDIAADAPTER_H

#include "MediaPlayer.h"
#include "AdvancedMediaPlayer.h"
#include <string>
#include "VlcPlayer.h"
#include "Mp4Player.h"

/// <summary>
/// 实现抽象类 MediaPlayer 的适配器类 MediaAdapter
/// </summary>
class MediaAdapter :
	public MediaPlayer
{

private:
	AdvancedMediaPlayer* advancedMusicPlayer;

public:
	inline MediaAdapter(std::string audioType) {
		if (audioType == "vlc") {
			advancedMusicPlayer = new VlcPlayer();
		}
		else if (audioType == "mp4") {
			advancedMusicPlayer = new Mp4Player();
		}
		else {
			advancedMusicPlayer = nullptr;
		}

	}
	/// <summary>
	/// 实现基类的纯虚播放函数
	/// </summary>
	/// <param name="audioType">音频类型</param>
	/// <param name="fileName">文件名称</param>
	inline virtual void play(std::string audioType, std::string fileName) override {
		if (audioType == "vlc") {
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (audioType == "mp4") {
			advancedMusicPlayer->playMp4(fileName);
		}
	}
};

#endif // !MEDIAADAPTER_H