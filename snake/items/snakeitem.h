#pragma once

#include "abstractItem.h"

#define SNAKE_LENGTH 12

#define INPUT_UP 'i'
#define INPUT_DOWN 'k'
#define INPUT_LEFT 'j'
#define INPUT_RIGHT 'l'

class SnakeItem : public AbstractItem{
	Direction direction;
	Points* pPoints;
	void initPoints();
	Direction toOrientation(char inputChar);
	void shiftHead();
	void shiftToX(Point* pPrevPoint, Point* pPoint);
	void shiftToY(Point* pPrevPoint, Point* pPoint);
	void shiftBody(Point prevHead);
public:
	SnakeItem();
	~SnakeItem();
	void onDraw();
	void onInput(char inputChar);
	Points* getPoints();
};
