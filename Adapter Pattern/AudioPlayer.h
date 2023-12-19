#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "MediaPlayer.h"
#include "MediaAdapter.h"
#include <string>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� MediaPlayer ��ʵ���� AudioPlayer
/// </summary>
class AudioPlayer :
	public MediaPlayer
{

private:
	MediaAdapter* mediaAdapter;

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ��鲥�ź���
	/// </summary>
	/// <param name="audioType">��Ƶ����</param>
	/// <param name="fileName">�ļ�����</param>
	inline virtual void play(std::string audioType, std::string fileName) override {
		// ���� map3 �����ļ�������֧��
		if (audioType == "mp3") {
			std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
		}
		// mediaAdapter �ṩ�˲��������ļ���ʽ��֧��
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