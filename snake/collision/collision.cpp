#include "Collision.h"
#include "../items/AbstractItem.h"
#include <initializer_list>
#include <list>

const char* CollisionException::what() const
{
	return "Collision Detected. Game Over";
}

Collision::Collision(initializer_list<AbstractItem*>* pItems) 
{
	this->pItems = pItems;
	SetTotalDots();
}

void Collision::CheckCollision(int dotsDrawn) throw(CollisionException) 
{
	SetTotalDots();
	if (dotsDrawn < totalDots) 
	{
		bool shouldStopGame = true;
		if (pItems->size() > 1) 
		{
			auto pItemsIterator = pItems->begin();
			AbstractItem* pSnakeItem = *pItemsIterator;
			AbstractItem* pFoodItem = *++pItemsIterator;
			Point* pSnakeHead = *(pSnakeItem->GetPoints()->begin());
			Point* pFood = *(pFoodItem->GetPoints()->begin());
			if (HasOverlapped(*pSnakeHead, *pFood)) 
			{
				shouldStopGame = false;
				pSnakeItem->OnCollision();
				pFoodItem->OnCollision();
			}
		}
		if (shouldStopGame) 
		{
			throw CollisionException();
		}
	}
}

void Collision::SetTotalDots() 
{
	this->totalDots = 0;
	for (auto pItemsIterator = pItems->begin(); pItemsIterator != pItems->end(); pItemsIterator++) 
	{
		totalDots += (*pItemsIterator)->GetPointsCount();
	}
}

bool Collision::HasOverlapped(Point snakePoint, Point foodPoint) 
{
	bool overlapped = true;
	overlapped = overlapped && ((snakePoint.x == foodPoint.x) || ((snakePoint.x + 1) == foodPoint.x) || ((snakePoint.x - 1) == foodPoint.x));
	overlapped = overlapped && ((snakePoint.y == foodPoint.y) || ((snakePoint.y + 1) == foodPoint.y) || ((snakePoint.y - 1) == foodPoint.y));
	return overlapped;
}