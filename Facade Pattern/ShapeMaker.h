#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

/// <summary>
/// Õ‚π€¿‡ ShapeMaker
/// </summary>
class ShapeMaker
{

private:
	Shape* rectangle;
	Shape* ellipse;

public:
	inline ShapeMaker() {
		rectangle = new Rectangle();
		ellipse = new Ellipse();
	}

	void renderRectangle() {
		rectangle->render();
	}
	void renderEllipse() {
		ellipse->render();
	}
	inline ~ShapeMaker() {
		delete rectangle;
		delete ellipse;
	}
};

#endif // !SHAPEMAKER_H