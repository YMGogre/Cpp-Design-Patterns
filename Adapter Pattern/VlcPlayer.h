#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include "AdvancedMediaPlayer.h"
#include <string>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� AdvancedMediaPlayer ��ʵ���� VlcPlayer
/// </summary>
class VlcPlayer :
	public AdvancedMediaPlayer
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ��鲥�� vlc �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	inline virtual void playVlc(std::string fileName) override {
		std::cout << "Playing vlc file. Name: " << fileName << std::endl;
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ��鲥�� mp4 �ļ�����
	/// </summary>
	/// <param name="fileName">�ļ�����</param>
	inline virtual void playMp4(std::string fileName) override {
		// ʲôҲ����
	}
};

#endif // !VLCPLAYER_H