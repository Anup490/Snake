#pragma once
#include <exception>
using namespace std;

struct CollisionException : exception 
{
	const char* what() const override;
};

namespace std
{
	template <class _Elem>
	class initializer_list;
}

class Collision 
{
	initializer_list<class AbstractItem*>* pItems;
	int totalDots;
	void SetTotalDots();
	bool HasOverlapped(struct Point snakePoint, Point foodPoint);
public:
	Collision(initializer_list<AbstractItem*>* pItems);
	void CheckCollision(int dotsDrawn) throw(CollisionException);
};