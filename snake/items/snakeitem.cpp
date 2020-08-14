#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->pPoints = new Points(SNAKE_LENGTH);
	initPoints();
}
SnakeItem::~SnakeItem() {
	delete pPoints;
}

void SnakeItem::onDraw() {
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		Point* pPoint = (pPoints->pPointArray)+i;
		(pPoint->x)++;
		pPoint->y = 0;
	}
}

Points* SnakeItem::getPoints() {
	return pPoints;
}

void SnakeItem::initPoints() {
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		Point* pPoint = (pPoints->pPointArray) + i;
		pPoint->x = i;
		pPoint->y = 0;
	}
}
