#pragma once

namespace std
{
	template <class _Ty>
	class allocator;

	template <class _Ty, class _Alloc = allocator<_Ty>>
	class list;
}

using namespace std;

enum class Direction 
{
	PX, PY, NX, NY, NONE
};

struct Point
{
	int x;
	int y;
};

class AbstractItem 
{
public:
	virtual void OnDraw() = 0;
	virtual list<Point*>* GetPoints() = 0;
	virtual void OnCollision() = 0;
	virtual int GetPointsCount() = 0;
	virtual ~AbstractItem() = default;
};