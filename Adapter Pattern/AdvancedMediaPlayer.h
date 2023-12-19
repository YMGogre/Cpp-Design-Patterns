#ifndef ADVANCEDMEDIAPLAYER_H
#define ADVANCEDMEDIAPLAYER_H

#include <string>

/// <summary>
/// ������ AdvancedMediaPlayer
/// </summary>
class AdvancedMediaPlayer
{

public:
	/// <summary>
	/// ���鲥�� vlc �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	virtual void playVlc(std::string fileName) = 0;
	/// <summary>
	/// ���鲥�� mp4 �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	virtual void playMp4(std::string fileName) = 0;
	virtual ~AdvancedMediaPlayer() {}
};

#endif // !ADVANCEDMEDIAPLAYER_H