#include "Snakeitem.h"
#include "../constant/Constants.h"
#include <list>

SnakeItem::SnakeItem() 
{
	this->direction = Direction::PX;
	this->pPoints = new list<Point*>();
	this->pNewTail = new Point;
	InitPoints();
	this->snakeLength = pPoints->size();
}

SnakeItem::~SnakeItem() 
{
	for (auto pPointsIterator = pPoints->begin(); pPointsIterator != pPoints->end(); pPointsIterator++) 
	{
		Point* pPoint = *pPointsIterator;
		delete pPoint;
	}
	delete pPoints;
	delete pNewTail;
}

void SnakeItem::OnDraw() 
{
	Point* pHead = *(pPoints->begin());
	Point originalHead = *pHead;
	ShiftHead(pHead);
	ShiftBody(originalHead);
}

void SnakeItem::OnInput(char inputChar) 
{
	Direction inputDirection = ToDirection(inputChar);
	if (((direction == Direction::PX) || (direction == Direction::NX))
		&& ((inputDirection == Direction::PY) || (inputDirection == Direction::NY))) 
	{
		direction = inputDirection;
	}
	else if (((direction == Direction::PY) || (direction == Direction::NY))
		&& ((inputDirection == Direction::PX) || (inputDirection == Direction::NX))) 
	{
		direction = inputDirection;
	}
}

list<Point*>* SnakeItem::GetPoints() 
{
	return pPoints;
}

void SnakeItem::OnCollision() 
{
	Point* pNewPoint = new Point;
	pNewPoint->x = pNewTail->x;
	pNewPoint->y = pNewTail->y;
	pPoints->push_back(pNewPoint);
	this->snakeLength = pPoints->size();
}

int SnakeItem::GetPointsCount() 
{
	return snakeLength;
}

void SnakeItem::InitPoints() 
{
	for (int i = (INITIAL_SNAKE_LENGTH - 1); i >=0 ; i--) 
	{
		Point* pPoint = new Point;
		pPoint->x = i;
		pPoint->y = 0;
		pPoints->push_back(pPoint);
	}
}

void SnakeItem::ShiftHead(Point* pHead) 
{
	Direction nextDirection = direction;
	switch (nextDirection) 
	{
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

void SnakeItem::ShiftBody(Point prevHead) 
{
	Point bufferSave;
	Point bufferAssign = prevHead;
	auto pPointsIterator = pPoints->begin();
	pPointsIterator++;
	for (; pPointsIterator != pPoints->end(); pPointsIterator++) 
	{
		Point* pPoint = *pPointsIterator;
		bufferSave = *pPoint;
		*pPoint = bufferAssign;
		bufferAssign = bufferSave;
		auto iterator = pPointsIterator;
		if (++iterator == pPoints->end()) 
		{
			pNewTail->x = bufferSave.x;
			pNewTail->y = bufferSave.y;
		}
	}
}

Direction SnakeItem::ToDirection(char inputChar) 
{
	switch (inputChar) 
	{
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