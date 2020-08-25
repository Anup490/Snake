#pragma once

#include "abstractItem.h"

#define SNAKE_LENGTH 6

#define INPUT_UP 'i'
#define INPUT_DOWN 'k'
#define INPUT_LEFT 'j'
#define INPUT_RIGHT 'l'


enum class Orientation {
	PX, PY, NX, NY, NONE
};

class SnakeItem : public AbstractItem{
	Orientation newOrientation;
	Orientation oldOrientation;
	Points* pPoints;
	Point head;
	Point tail;
	void initPoints();
	Orientation toOrientation(char inputChar);
	void updateHeadAndTail();
public:
	SnakeItem();
	~SnakeItem();
	void onDraw();
	void onInput(char inputChar);
	Points* getPoints();
};
