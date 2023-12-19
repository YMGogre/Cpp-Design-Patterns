#ifndef SHAPE_H
#define SHAPE_H

/// <summary>
/// ³éÏóÀà Shape
/// </summary>
class Shape
{

public:
	/// <summary>
	/// ´¿ĞéäÖÈ¾º¯Êı
	/// </summary>
	virtual void render() = 0;
	virtual ~Shape() {}
};

#endif // !SHAPE_H