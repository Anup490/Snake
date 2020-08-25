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

/*
	RULE 

	Compare with previous point instead with head

	PX = Lesser X than Previous && Same Y as previous
	NX = Greater X than Previous && Same Y as previous
	PY = Lesser Y than Previous && Same X as previous
	NY = Greater Y than Previous && Same X as previous

*/

void SnakeItem::onDraw() {
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		Point* pPoint = (pPoints->pPointArray) + i;
		if (newOrientation == Orientation::PY) {
			if ((head.x) > (pPoint->x)) {
				(pPoint->x)++;
			}
			else if ((head.x) < (pPoint->x)) {
				(pPoint->x)--;
			}
			else {
				(pPoint->y)++;
			}
		}
		else if (newOrientation == Orientation::NX) {
			if ((head.y) < (pPoint->y)) {
				(pPoint->y)--;
			}
			else if ((head.y) > (pPoint->y)) {
				(pPoint->y)++;
			}
			else {
				(pPoint->x)--;
			}
		}
		else if (newOrientation == Orientation::NY) {
			if ((head.x) > (pPoint->x)) {
				(pPoint->x)++;
			}
			else if ((head.x) < (pPoint->x)) {
				(pPoint->x)--;
			}
			else {
				(pPoint->y)--;
			}
		}
		else if (newOrientation == Orientation::PX) {
			if ((head.y) < (pPoint->y)) {
				(pPoint->y)--;
			}
			else if ((head.y) > (pPoint->y)) {
				(pPoint->y)++;
			}
			else {
				(pPoint->x)++;
			}
		}
	}
	updateHeadAndTail();
}

void SnakeItem::onInput(char inputChar) {
	Orientation inputOrientation = toOrientation(inputChar);
	if (((newOrientation == Orientation::PX) || (newOrientation == Orientation::NX))
		&& ((inputOrientation == Orientation::PY) || (inputOrientation == Orientation::NY))) {
		newOrientation = inputOrientation;
	}
	else if (((newOrientation == Orientation::PY) || (newOrientation == Orientation::NY))
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
