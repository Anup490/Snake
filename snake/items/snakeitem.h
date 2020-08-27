#pragma once

#include "abstractItem.h"

#define SNAKE_LENGTH 6

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
	void shiftOnPY(Point* pPrevPoint, Point* pPoint);
	void shiftOnNX(Point* pPrevPoint, Point* pPoint);
	void shiftOnNY(Point* pPrevPoint, Point* pPoint);
	void shiftOnPX(Point* pPrevPoint, Point* pPoint);
public:
	SnakeItem();
	~SnakeItem();
	void onDraw();
	void onInput(char inputChar);
	Points* getPoints();
};
