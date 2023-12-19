#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "MediaPlayer.h"
#include "MediaAdapter.h"
#include <string>
#include <iostream>

/// <summary>
/// 实现抽象类 MediaPlayer 的实体类 AudioPlayer
/// </summary>
class AudioPlayer :
	public MediaPlayer
{

private:
	MediaAdapter* mediaAdapter;

public:
	/// <summary>
	/// 实现基类的纯虚播放函数
	/// </summary>
	/// <param name="audioType">音频类型</param>
	/// <param name="fileName">文件名称</param>
	inline virtual void play(std::string audioType, std::string fileName) override {
		// 播放 map3 音乐文件的内置支持
		if (audioType == "mp3") {
			std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
		}
		// mediaAdapter 提供了播放其他文件格式的支持
		else if (audioType == "vlc" || audioType == "mp4") {
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, fileName);
		}
		else {
			std::cout << "Invalid media. " << audioType << " format not supported" << std::endl;
		}
	}
};

#endif // !AUDIOPLAYER_H