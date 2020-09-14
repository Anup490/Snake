#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->direction = Direction::PX;
	this->pPoints = new list<Point*>();
	this->pNewTail = new Point;
	initPoints();
	this->snakeLength = pPoints->size();
}

SnakeItem::~SnakeItem() {
	for (auto pPointsIterator = pPoints->begin(); pPointsIterator != pPoints->end(); pPointsIterator++) {
		Point* pPoint = *pPointsIterator;
		delete pPoint;
	}
	delete pPoints;
	delete pNewTail;
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

void SnakeItem::onCollision() {
	Point* pNewPoint = new Point;
	pNewPoint->x = pNewTail->x;
	pNewPoint->y = pNewTail->y;
	pPoints->push_back(pNewPoint);
	this->snakeLength = pPoints->size();
}

int SnakeItem::getPointsCount() {
	return snakeLength;
}

void SnakeItem::initPoints() {
	for (int i = (INITIAL_SNAKE_LENGTH - 1); i >=0 ; i--) {
		Point* pPoint = new Point;
		pPoint->x = i;
		pPoint->y = 0;
		pPoints->push_back(pPoint);
		/*if (i=0) {
			pTail = pPoint;
		}*/
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

		auto iterator = pPointsIterator;
		if (++iterator == pPoints->end()) {
			pNewTail->x = bufferSave.x;
			pNewTail->y = bufferSave.y;
		}
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