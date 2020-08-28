#include "collision.h"

Collision::Collision(int totalDots) {
	this->totalDots = totalDots;
}

void Collision::checkCollision(int dotsDrawn) throw(CollisionException) {
	if (dotsDrawn < totalDots) {
		throw CollisionException();
	}
}