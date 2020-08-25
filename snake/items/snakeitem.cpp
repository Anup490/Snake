#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->orientation = Orientation::PX;
	this->pPoints = new Points(SNAKE_LENGTH);
	initPoints();
}
SnakeItem::~SnakeItem() {
	delete pPoints;
}

void SnakeItem::onDraw() {
	shiftHead();
	for (int i = (SNAKE_LENGTH-2); i >= 0; i--) {
		Point* pPrevPoint = (pPoints->pPointArray) + (i+1);
		Point* pPoint = (pPoints->pPointArray) + i;
		if (orientation == Orientation::PY) {
			shiftOnPY(pPrevPoint,pPoint);
		}
		else if (orientation == Orientation::NX) {
			shiftOnNX(pPrevPoint, pPoint);
		}
		else if (orientation == Orientation::NY) {
			shiftOnNY(pPrevPoint, pPoint);
		}
		else if (orientation == Orientation::PX) {
			shiftOnPX(pPrevPoint, pPoint);
		}
	}
}

void SnakeItem::onInput(char inputChar) {
	Orientation inputOrientation = toOrientation(inputChar);
	if (((orientation == Orientation::PX) || (orientation == Orientation::NX))
		&& ((inputOrientation == Orientation::PY) || (inputOrientation == Orientation::NY))) {
		orientation = inputOrientation;
	}
	else if (((orientation == Orientation::PY) || (orientation == Orientation::NY))
		&& ((inputOrientation == Orientation::PX) || (inputOrientation == Orientation::NX))) {
		orientation = inputOrientation;
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

Orientation SnakeItem::toOrientation(char inputChar) {
	switch (inputChar){
	case INPUT_UP:
		return Orientation::NY;
	case INPUT_DOWN:
		return Orientation::PY;
	case INPUT_LEFT:
		return Orientation::NX;
	case INPUT_RIGHT:
		return Orientation::PX;
	default:
		return Orientation::NONE;
	}
}

void SnakeItem::shiftHead() {
	Point* pHead = (pPoints->pPointArray) + (SNAKE_LENGTH - 1);
	if (orientation == Orientation::PY) {
		(pHead->y)++;
	}
	else if (orientation == Orientation::NX) {
		(pHead->x)--;
	}
	else if (orientation == Orientation::NY) {
		(pHead->y)--;
	}
	else if (orientation == Orientation::PX) {
		(pHead->x)++;
	}
}

void SnakeItem::shiftOnPY(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->y) > (pPrevPoint->y)) {
		(pPoint->y)--;
	}
	else if ((pPoint->x) < (pPrevPoint->x)) {
		(pPoint->x)++;
	}
	else if ((pPoint->x) > (pPrevPoint->x)) {
		(pPoint->x)--;
	}
	else {
		(pPoint->y)++;
	}
}

void SnakeItem::shiftOnNX(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->x) < (pPrevPoint->x)) {
		(pPoint->x)++;
	}
	else if ((pPoint->y) > (pPrevPoint->y)) {
		(pPoint->y)--;
	}
	else if ((pPoint->y) < (pPrevPoint->y)) {
		(pPoint->y)++;
	}
	else {
		(pPoint->x)--;
	}
}

void SnakeItem::shiftOnNY(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->y) < (pPrevPoint->y)) {
		(pPoint->y)++;
	}
	else if ((pPoint->x) < (pPrevPoint->x)) {
		(pPoint->x)++;
	}
	else if ((pPoint->x) > (pPrevPoint->x)) {
		(pPoint->x)--;
	}
	else {
		(pPoint->y)--;
	}
}

void SnakeItem::shiftOnPX(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->x) > (pPrevPoint->x)) {
		(pPoint->x)--;
	}
	else if ((pPoint->y) > (pPrevPoint->y)) {
		(pPoint->y)--;
	}
	else if ((pPoint->y) < (pPrevPoint->y)) {
		(pPoint->y)++;
	}
	else {
		(pPoint->x)++;
	}
}


