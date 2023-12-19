#ifndef GAME_H
#define GAME_H

/// <summary>
/// ������ Game������ģ�巽��������Ϊ final���Ա��ⱻ��д
/// </summary>
class Game
{

public:
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

	// ģ��
	inline virtual void play() final {
		// ��ʼ����Ϸ
		initialize();

		// ��ʼ��Ϸ
		startPlay();

		// ������Ϸ
		endPlay();
	}
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Game() {}
};

#endif // !GAME_H