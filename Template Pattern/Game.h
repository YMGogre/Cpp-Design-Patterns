#ifndef GAME_H
#define GAME_H

/// <summary>
/// 抽象类 Game，它的模板方法被设置为 final，以避免被重写
/// </summary>
class Game
{

protected:
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

public:
	// 模板
	inline virtual void play() final {
		// 初始化游戏
		initialize();

		// 开始游戏
		startPlay();

		// 结束游戏
		endPlay();
	}
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Game() {}
};

#endif // !GAME_H