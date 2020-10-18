#pragma once
#include "AbstractItem.h"

class SnakeItem : public AbstractItem
{
	Direction direction;
	list<Point*>* pPoints;
	Point* pNewTail;
	int snakeLength;
	void InitPoints();
	void ShiftHead(Point* pHead);
	void ShiftBody(Point prevHead);
	Direction ToDirection(char inputChar);
public:
	SnakeItem();
	~SnakeItem();
	void OnDraw() override;
	void OnInput(char inputChar);
	list<Point*>* GetPoints() override;
	void OnCollision() override;
	int GetPointsCount() override;
};