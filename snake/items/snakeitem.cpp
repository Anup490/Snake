#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->newOrientation = Orientation::PX;
	this->oldOrientation = Orientation::PX;
	this->pPoints = new Points(SNAKE_LENGTH);
	initPoints();
}
SnakeItem::~SnakeItem() {
	delete pPoints;
}

void SnakeItem::onDraw() {
	if (newOrientation == Orientation::PY) {
		for (int i = 0; i < SNAKE_LENGTH; i++) {
			Point* pPoint = (pPoints->pPointArray) + i;
			if ((pPoint->x) != (head.x)) {
				if ((head.x)>(pPoint->x)) {
					(pPoint->x)++;
				}
				else {
					(pPoint->x)--;
				}
			}
			else {
				(pPoint->y)++;
			}
		}
	}
	else if (newOrientation == Orientation::NX) {
		for (int i = 0; i < SNAKE_LENGTH; i++) {
			Point* pPoint = (pPoints->pPointArray) + i;
			if ((pPoint->y) != (head.y)) {
				if ((head.y) < (pPoint->y)) {
					(pPoint->y)--;
				}
				else {
					(pPoint->y)++;
				}
			}
			else {
				(pPoint->x)--;
			}
		}
	}
	else if (newOrientation == Orientation::NY) {
		int newX = head.x;
		for (int i = 0; i < SNAKE_LENGTH; i++) {
			Point* pPoint = (pPoints->pPointArray) + i;
			if ((pPoint->x) != (head.x)) {
				if ((head.x) > (pPoint->x)) {
					(pPoint->x)++;
				}
				else {
					(pPoint->x)--;
				}
			}
			else {
				(pPoint->y)--;
			}
		}
	}
	else if (newOrientation == Orientation::PX) {
		for (int i = 0; i < SNAKE_LENGTH; i++) {
			Point* pPoint = (pPoints->pPointArray) + i;
			if ((pPoint->y) != (head.y)) {
				if ((head.y) < (pPoint->y)) {
					(pPoint->y)--;
				}
				else {
					(pPoint->y)++;
				}
			}
			else {
				(pPoint->x)++;
			}
		}
	}
	oldOrientation = newOrientation;
	updateHeadAndTail();
}

void SnakeItem::onInput(char inputChar) {
	Orientation inputOrientation = toOrientation(inputChar);
	if (((oldOrientation == Orientation::PX) || (oldOrientation == Orientation::NX)) 
		&& ((inputOrientation == Orientation::PY) || (inputOrientation == Orientation::NY))) {
		newOrientation = inputOrientation;
	}
	else if (((oldOrientation == Orientation::PY) || (oldOrientation == Orientation::NY))
		&& ((inputOrientation == Orientation::PX) || (inputOrientation == Orientation::NX))) {
		newOrientation = inputOrientation;
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
	updateHeadAndTail();
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

void SnakeItem::updateHeadAndTail() {
	this->head = *((pPoints->pPointArray) + (SNAKE_LENGTH-1));
	this->tail = *(pPoints->pPointArray);
}
