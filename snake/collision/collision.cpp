#include "Collision.h"

const char* CollisionException::what() const{
	return "Collision Detected. Game Over";
}

Collision::Collision(initializer_list<AbstractItem*>* pItems) {
	this->pItems = pItems;
	setTotalDots();
}

void Collision::checkCollision(int dotsDrawn) throw(CollisionException) {
	setTotalDots();
	if (dotsDrawn < totalDots) {
		bool shouldStopGame = true;
		if (pItems->size() > 1) {
			auto pItemsIterator = pItems->begin();
			AbstractItem* pSnakeItem = *pItemsIterator;
			AbstractItem* pFoodItem = *++pItemsIterator;
			Point* pSnakeHead = *(pSnakeItem->getPoints()->begin());
			Point* pFood = *(pFoodItem->getPoints()->begin());
			if (hasOverlapped(*pSnakeHead, *pFood)) {
				shouldStopGame = false;
				pSnakeItem->onCollision();
				pFoodItem->onCollision();
			}
		}
		if (shouldStopGame) {
			throw CollisionException();
		}
	}
}

void Collision::setTotalDots() {
	this->totalDots = 0;
	for (auto pItemsIterator = pItems->begin(); pItemsIterator != pItems->end(); pItemsIterator++) {
		totalDots += (*pItemsIterator)->getPointsCount();
	}
}

bool Collision::hasOverlapped(Point snakePoint, Point foodPoint) {
	bool overlapped = true;
	overlapped = overlapped && ((snakePoint.x == foodPoint.x) || ((snakePoint.x + 1) == foodPoint.x) || ((snakePoint.x - 1) == foodPoint.x));
	overlapped = overlapped && ((snakePoint.y == foodPoint.y) || ((snakePoint.y + 1) == foodPoint.y) || ((snakePoint.y - 1) == foodPoint.y));
	return overlapped;
}