#include "Painter.h"
#include "../items/AbstractItem.h"
#include "../constant/Constants.h"
#include <initializer_list>
#include <list>
#include <iostream>
#include <string>

Painter::Painter(initializer_list<AbstractItem*>* pItems) 
{
	this->pItems = pItems;
}

int Painter::Paint() 
{
	int totalDotsDrawn = 0;
	Row rows[MAX_Y_AXIS];
	InitRows(rows);
	MakeFrame(rows);
	system("cls");
	DrawFrame(rows, totalDotsDrawn);
	AddBoundaryAndScore(totalDotsDrawn);
	NotifyItems();
	return totalDotsDrawn;
}

void Painter::InitRows(Row* pRows) 
{
	for (int i = 0; i < MAX_Y_AXIS; i++) 
	{
		Row* pNewRow = new Row(MAX_X_AXIS);
		pRows[i] = *pNewRow;
		delete pNewRow;
	}
}

void Painter::MakeFrame(Row* pRows) 
{
	for (AbstractItem* pItem : *pItems) 
	{
		list<Point*>* pPoints = pItem->GetPoints();
		for (Point* pPoint : *pPoints) 
		{
			if (IsWithinBounds(*pPoint)) 
			{
				Row* pRow = pRows + (pPoint->y);
				bool* pPointFlag = (pRow->pPointFlags) + (pPoint->x);
				*(pPointFlag) = true;
				if (((pPoint->x) + 1) > (pRow->size)) 
				{
					pRow->size = (pPoint->x) + 1;
				}
			}
		}
	}
}

bool Painter::IsWithinBounds(Point point) 
{
	return (point.x < MAX_X_AXIS) && (point.x >= 0) && (point.y < MAX_Y_AXIS) && (point.y >= 0);
}

void Painter::DrawFrame(Row* pRows, int& rTotalDotsDrawn) 
{
	std::string row;
	for (int i = 0; i < MAX_Y_AXIS; i++) 
	{
		for (int j = 0; j < pRows[i].size; j++) 
		{
			bool glow = *(pRows[i].pPointFlags + j);
			if (glow == true) 
			{
				row.append("*");
				rTotalDotsDrawn++;
			}
			else 
				row.append(" ");
		}
		row.append("\n");
	}
	cout << row;
	row.clear();
}

void Painter::AddBoundaryAndScore(int& rTotalDotsDrawn)
{
	for (int i = 0; i < MAX_X_AXIS; i++) 
	{
		cout << "=";
	}
	cout << "SCORE :: " << rTotalDotsDrawn - 1 - INITIAL_SNAKE_LENGTH << endl;
}

void Painter::NotifyItems() 
{
	for (AbstractItem* pItem : *pItems) 
	{
		pItem->OnDraw();
	}
}