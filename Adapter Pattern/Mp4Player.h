#ifndef MP4PLAYER_H
#define MP4PLAYER_H

#include "AdvancedMediaPlayer.h"
#include <string>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� AdvancedMediaPlayer ��ʵ���� Mp4Player
/// </summary>
class Mp4Player :
	public AdvancedMediaPlayer
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ��鲥�� vlc �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	inline virtual void playVlc(std::string fileName) override {
		// ʲôҲ����
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ��鲥�� mp4 �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	inline virtual void playMp4(std::string fileName) override {
		std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
	}
};

#endif // !MP4PLAYER_H