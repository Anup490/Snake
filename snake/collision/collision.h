#pragma once
#include <exception>
using namespace std;

struct CollisionException : exception {
	const char* what() const override{
		return "Collision Detected. Game Over";
	}
};

class Collision {
	int totalDots;
public:
	Collision(int totalDots);
	void checkCollision(int dotsDrawn) throw(CollisionException);
};