#ifndef ADVANCEDMEDIAPLAYER_H
#define ADVANCEDMEDIAPLAYER_H

#include <string>

/// <summary>
/// 抽象类 AdvancedMediaPlayer
/// </summary>
class AdvancedMediaPlayer
{

public:
	/// <summary>
	/// 纯虚播放 vlc 文件函数
	/// </summary>
	/// <param name="fileName">文件名称</param>
	virtual void playVlc(std::string fileName) = 0;
	/// <summary>
	/// 纯虚播放 mp4 文件函数
	/// </summary>
	/// <param name="fileName">文件名称</param>
	virtual void playMp4(std::string fileName) = 0;
	virtual ~AdvancedMediaPlayer() {}
};

#endif // !ADVANCEDMEDIAPLAYER_H