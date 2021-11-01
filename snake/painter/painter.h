#pragma once

namespace std
{
	template <class _Elem>
	class initializer_list;
}

struct Row
{
	bool* pPointFlags;
	int size = 0;
	Row() = default;
	Row(int boolSize) 
	{
		size = boolSize;
		this->pPointFlags = new bool[boolSize];
	}
	~Row() 
	{
		delete[] pPointFlags;
	}
	Row& operator=(Row& anotherRow)
	{
		this->pPointFlags = new bool[anotherRow.size];
		for (int i=0; i< anotherRow.size; i++)
		{
			this->pPointFlags[i] = anotherRow.pPointFlags[i];
		}
		return *this;
	}
};

using namespace std;

class Painter 
{
	initializer_list<class AbstractItem*>* pItems;
	void InitRows(Row* pRows);
	void MakeFrame(Row* pRows);
	bool IsWithinBounds(struct Point point);
	void DrawFrame(Row* pRows, int& rTotalDotsDrawn);
	void AddBoundaryAndScore(int& rTotalDotsDrawn);
	void NotifyItems();
public:
	Painter(initializer_list<AbstractItem*> *pItems);
	int Paint();
};