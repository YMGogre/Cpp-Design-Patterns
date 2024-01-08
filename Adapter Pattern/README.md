[上一篇](../Proxy%20Pattern/README.md)

---

# 适配器模式 Adapter

## 1、动机

* 在软件系统中，由于应用环境的变化，常常需要将 “一些现存的对象” 放在新的环境中应用，但是新环境要求的接口是这些现存对象所不满足的。
* 如何应对这种 “迁移的变化”？如何既能利用现有对象的良好实现，同时又能满足新的应用环境所要求的接口？

> 适配器模式是作为两个不兼容的接口之间的桥梁。这种类型的设计模式属于结构型模式，它结合了两个独立接口的功能。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>将一个类的接口转换成客户希望的另外一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。</dd>
    <dt>关键代码</dt>
    <dd>适配器继承或依赖已有的对象，实现想要的目标接口。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个接口 MediaPlayer：

```cpp
class MediaPlayer
{

public:
	virtual void play(std::string audioType, std::string fileName) = 0;
	virtual ~MediaPlayer() {}
};
```

> MediaPlayer 包含一个纯虚成员函数 `play(std::string audioType, std::string fileName)` 用于播放媒体文件。其中函数参数：
> * `audioType`：音频类型；
> * `fileName`：文件名称。

我们还要创建一个接口 AdvancedMediaPlayer：

```cpp
class AdvancedMediaPlayer
{

public:
	virtual void playVlc(std::string fileName) = 0;
	virtual void playMp4(std::string fileName) = 0;
	virtual ~AdvancedMediaPlayer() {}
};
```

> AdvancedMediaPlayer 包含一些纯虚成员函数，其中：
> * `playVlc(std::string fileName)`：用于播放 vlc 文件；
> * `playMp4(std::string fileName)`：用于播放 mp4 文件。

### 步骤二

接下来我们创建实现了 AdvancedMediaPlayer 类的实体类 VlcPlayer 和 Mp4Player。它们将重写抽象类的方法以播放特定的媒体文件：

```cpp
class VlcPlayer :
	public AdvancedMediaPlayer
{

public:
	inline virtual void playVlc(std::string fileName) override {
		std::cout << "Playing vlc file. Name: " << fileName << std::endl;
	}

	inline virtual void playMp4(std::string fileName) override {
		// 什么也不做
	}
};
```

```cpp
class Mp4Player :
	public AdvancedMediaPlayer
{

public:
	inline virtual void playVlc(std::string fileName) override {
		// 什么也不做
	}

	inline virtual void playMp4(std::string fileName) override {
		std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
	}
};
```

### 步骤三

现在假定我们有一个 **AudioPlayer** 类实现了 MediaPlayer 接口，其默认提供了播放 mp3 格式音频文件的功能。但是我们还想让 **AudioPlayer** 能够播放其他格式的音频文件。

为了实现这个功能，我们可以创建一个实现了 MediaPlayer 接口的适配器类 MediaAdapter，其使用 AdvancedMediaPlayer 对象来播放所需的格式。

我们的 MediaAdapter 类如下：

```cpp
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

	inline virtual void play(std::string audioType, std::string fileName) override {
		if (audioType == "vlc") {
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (audioType == "mp4") {
			advancedMusicPlayer->playMp4(fileName);
		}
	}
	inline virtual ~MediaAdapter() {
		delete advancedMusicPlayer;
	}
};
```

> 🔔 当然适配器类也可以选择继承 AdvancedMediaPlayer （符合新接口的规范）并在内部拥有一个 MediaPlayer 指针（引用一个 AudioPlayer 对象以在内部实现老接口到新接口的转化）。
> 
> 正所谓适配器继承或依赖已有对象，实现想要的目标接口。

### 步骤四

接下来我们创建实现了 MediaPlayer 类的实体类 **AudioPlayer**。其使用适配器类 MediaAdapter 传递所需的音频类型，不需要知道能播放所需格式音频的实际类。

我们的 AudioPlayer 类如下：

```cpp
class AudioPlayer :
	public MediaPlayer
{

private:
	MediaAdapter* mediaAdapter;

public:
	inline virtual void play(std::string audioType, std::string fileName) override {
		// 播放 map3 音乐文件的内置支持
		if (audioType == "mp3") {
			std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
		}
		// mediaAdapter 提供了播放其他文件格式的支持
		else if (audioType == "vlc" || audioType == "mp4") {
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, fileName);
		}
		else {
			std::cout << "Invalid media. " << audioType << " format not supported" << std::endl;
		}
	}
	inline virtual ~AudioPlayer() {
		delete mediaAdapter;
	}
};
```

### 步骤五

在 `main()` 函数中，我们使用 AudioPlayer 来播放不同格式的音频文件：

```cpp
int main() {
	AudioPlayer audioPlayer;

    audioPlayer.play("mp3", "beyond the horizon.mp3");
    audioPlayer.play("mp4", "alone.mp4");
    audioPlayer.play("vlc", "far far away.vlc");
    audioPlayer.play("avi", "mind me.avi");
}
```

### 步骤六

执行程序，输出结果：

```plain
Playing mp3 file. Name: beyond the horizon.mp3
Playing mp4 file. Name: alone.mp4
Playing vlc file. Name: far far away.vlc
Invalid media. avi format not supported
```

### 步骤七

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 适配器模式主要应用于 “希望复用一些现存的类，但是接口又与复用环境要求不一致的情况”，在遗留代码复用、类库迁移等方面非常有用。
* GOF 23 定义了两种适配器模式的实现结构：对象适配器和类适配器。但类适配器采用 “多继承” 的实现方式，一般不推荐使用。对象适配器采用 “对象组合” 的方法，更符合松耦合精神。
* 适配器模式可以实现得非常灵活，不必拘泥于 GOF 23 中定义的两种结构。例如，完全可以将适配器模式中的 “现存对象” 作为新的接口方法的参数，来达到适配的目的。

---

[下一篇](../Mediator%20Pattern/README.md)