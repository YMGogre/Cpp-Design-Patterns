#include "Shape.h"
#include "Circle.h"
#include "RedCircle.h"
#include "GreenCircle.h"

int main() {
	Circle redCircle(100, 100, 10, new RedCircle());
	Circle greenCircle(100, 100, 10, new GreenCircle());

	redCircle.render();
	greenCircle.render();
}