#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include<string>

/// <summary>
/// 抽象类 MediaPlayer
/// </summary>
class MediaPlayer
{

public:
	/// <summary>
	/// 纯虚播放函数
	/// </summary>
	/// <param name="audioType">音频类型</param>
	/// <param name="fileName">文件名称</param>
	virtual void play(std::string audioType, std::string fileName) = 0;
	virtual ~MediaPlayer() {}
};

#endif // !MEDIAPLAYER_H