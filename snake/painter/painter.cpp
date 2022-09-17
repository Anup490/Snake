#include "Painter.h"
#include "../items/AbstractItem.h"
#include "../constant/Constants.h"
#include <initializer_list>
#include <list>
#include <iostream>

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
	ShowFrame(frame);
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
	for (int i = 0; i < MAX_Y_AXIS; i++) 
	{
		for (int j = 0; j < pRows[i].size; j++) 
		{
			bool glow = *(pRows[i].pPointFlags + j);
			if (glow == true) 
			{
				frame.append("*");
				rTotalDotsDrawn++;
			}
			else 
				frame.append(" ");
		}
		frame.append("\n");
	}
}

void Painter::AddBoundaryAndScore(int& rTotalDotsDrawn)
{
	for (int i = 0; i < MAX_X_AXIS; i++) 
	{
		frame.append("=");
	}
	frame.append("SCORE :: ");
	frame.append(std::to_string(rTotalDotsDrawn - 1 - INITIAL_SNAKE_LENGTH));
	frame.append("\n");
}

void Painter::ShowFrame(std::string& frame)
{
	cout << frame;
	frame.clear();
}

void Painter::NotifyItems() 
{
	for (AbstractItem* pItem : *pItems) 
	{
		pItem->OnDraw();
	}
}