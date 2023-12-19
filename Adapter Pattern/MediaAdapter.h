#ifndef MEDIAADAPTER_H
#define MEDIAADAPTER_H

#include "MediaPlayer.h"
#include "AdvancedMediaPlayer.h"
#include <string>
#include "VlcPlayer.h"
#include "Mp4Player.h"

/// <summary>
/// ʵ�ֳ����� MediaPlayer ���������� MediaAdapter
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
	/// ʵ�ֻ���Ĵ��鲥�ź���
	/// </summary>
	/// <param name="audioType">��Ƶ����</param>
	/// <param name="fileName">�ļ�����</param>
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