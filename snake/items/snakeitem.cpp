#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->direction = Direction::PX;
	this->pPoints = new list<Point*>();
	initPoints();
}

SnakeItem::~SnakeItem() {
	for (auto pPointsIterator = pPoints->begin(); pPointsIterator != pPoints->end(); pPointsIterator++) {
		Point* pPoint = *pPointsIterator;
		delete pPoint;
	}
	delete pPoints;
}

void SnakeItem::onDraw() {
	Point* pHead = *(pPoints->begin());
	Point originalHead = *pHead;
	shiftHead(pHead);
	shiftBody(originalHead);
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

list<Point*>* SnakeItem::getPoints() {
	return pPoints;
}

void SnakeItem::initPoints() {
	for (int i = (SNAKE_LENGTH - 1); i >=0 ; i--) {
		Point* pPoint = new Point;
		pPoint->x = i;
		pPoint->y = 0;
		pPoints->push_back(pPoint);
	}
}

void SnakeItem::shiftHead(Point* pHead) {
	Direction nextDirection = direction;
	switch (nextDirection) {
	case Direction::PX:
		(pHead->x)++;
		break;
	case Direction::PY:
		(pHead->y)++;
		break;
	case Direction::NX:
		(pHead->x)--;
		break;
	case Direction::NY:
		(pHead->y)--;
	}
}

void SnakeItem::shiftBody(Point prevHead) {
	Point bufferSave;
	Point bufferAssign = prevHead;
	auto pPointsIterator = pPoints->begin();
	pPointsIterator++;
	for (; pPointsIterator != pPoints->end(); pPointsIterator++) {
		Point* pPoint = *pPointsIterator;
		bufferSave = *pPoint;
		*pPoint = bufferAssign;
		bufferAssign = bufferSave;
	}
}

Direction SnakeItem::toOrientation(char inputChar) {
	switch (inputChar) {
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