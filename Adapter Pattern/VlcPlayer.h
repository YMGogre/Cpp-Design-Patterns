#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include "AdvancedMediaPlayer.h"
#include <string>
#include <iostream>

/// <summary>
/// 实现抽象类 AdvancedMediaPlayer 的实体类 VlcPlayer
/// </summary>
class VlcPlayer :
	public AdvancedMediaPlayer
{

public:
	/// <summary>
	/// 实现基类的纯虚播放 vlc 文件函数
	/// </summary>
	/// <param name="fileName">文件名称</param>
	inline virtual void playVlc(std::string fileName) override {
		std::cout << "Playing vlc file. Name: " << fileName << std::endl;
	}
	/// <summary>
	/// 实现基类的纯虚播放 mp4 文件函数
	/// </summary>
	/// <param name="fileName">文件名称</param>
	inline virtual void playMp4(std::string fileName) override {
		// 什么也不做
	}
};

#endif // !VLCPLAYER_H