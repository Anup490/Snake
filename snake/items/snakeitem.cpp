#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->direction = Direction::PX;
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
		Direction prevPointDirection = pPrevPoint->direction;
		if ((prevPointDirection == Direction::PX) || ((prevPointDirection == Direction::NX))) {
			shiftToX(pPrevPoint, pPoint);
		}
		else if ((prevPointDirection == Direction::PY) || ((prevPointDirection == Direction::NY))) {
			shiftToY(pPrevPoint, pPoint);
		}
	}
}

void SnakeItem::onInput(char inputChar) {
	Direction inputOrientation = toOrientation(inputChar);
	if (((direction == Direction::PX) || (direction == Direction::NX))
		&& ((inputOrientation == Direction::PY) || (inputOrientation == Direction::NY))) {
		direction = inputOrientation;
	}
	else if (((direction == Direction::PY) || (direction == Direction::NY))
		&& ((inputOrientation == Direction::PX) || (inputOrientation == Direction::NX))) {
		direction = inputOrientation;
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
		pPoint->direction = Direction::PX;
	}
}

Direction SnakeItem::toOrientation(char inputChar) {
	switch (inputChar){
	case INPUT_UP:
		return Direction::NY;
	case INPUT_DOWN:
		return Direction::PY;
	case INPUT_LEFT:
		return Direction::NX;
	case INPUT_RIGHT:
		return Direction::PX;
	default:
		return Direction::NONE;
	}
}

void SnakeItem::shiftHead() {
	Point* pHead = (pPoints->pPointArray) + (SNAKE_LENGTH - 1);
	Direction nextDirection = direction;
	if (nextDirection == Direction::PY) {
		(pHead->y)++;
	}
	else if (nextDirection == Direction::NX) {
		(pHead->x)--;
	}
	else if (nextDirection == Direction::NY) {
		(pHead->y)--;
	}
	else if (nextDirection == Direction::PX) {
		(pHead->x)++;
	}
	pHead->direction = nextDirection;
}

void SnakeItem::shiftToX(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->y) > (pPrevPoint->y)) {
		(pPoint->y)--;
		if ((pPoint->y) == (pPrevPoint->y)) {
			pPoint->direction = pPrevPoint->direction;
		}
	}
	else if ((pPoint->y) < (pPrevPoint->y)) {
		(pPoint->y)++;
		if ((pPoint->y) == (pPrevPoint->y)) {
			pPoint->direction = pPrevPoint->direction;
		}
	}
	else if ((pPoint->x) > (pPrevPoint->x)) {
		(pPoint->x)--;
		pPoint->direction = pPrevPoint->direction;
	}
	else {
		(pPoint->x)++;
		pPoint->direction = pPrevPoint->direction;
	}
}

void SnakeItem::shiftToY(Point* pPrevPoint, Point* pPoint) {
	if ((pPoint->x) > (pPrevPoint->x)) {
		(pPoint->x)--;
		if ((pPoint->x) == (pPrevPoint->x)) {
			pPoint->direction = pPrevPoint->direction;
		}
	}
	else if ((pPoint->x) < (pPrevPoint->x)) {
		(pPoint->x)++;
		if ((pPoint->x) == (pPrevPoint->x)) {
			pPoint->direction = pPrevPoint->direction;
		}
	}
	else if ((pPoint->y) < (pPrevPoint->y)) {
		(pPoint->y)++;
		pPoint->direction = pPrevPoint->direction;
	}
	else {
		(pPoint->y)--;
		pPoint->direction = pPrevPoint->direction;
	}
}


