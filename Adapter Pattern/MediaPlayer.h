#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include<string>

/// <summary>
/// ������ MediaPlayer
/// </summary>
class MediaPlayer
{

public:
	/// <summary>
	/// ���鲥�ź���
	/// </summary>
	/// <param name="audioType">��Ƶ����</param>
	/// <param name="fileName">�ļ�����</param>
	virtual void play(std::string audioType, std::string fileName) = 0;
	virtual ~MediaPlayer() {}
};

#endif // !MEDIAPLAYER_H