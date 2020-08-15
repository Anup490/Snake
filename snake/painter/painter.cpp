#include "painter.h"

Painter::Painter(AbstractItem* pItems, int totalItems) {
	this->pItems = pItems;
	this->totalItems = totalItems;
}

void Painter::paint() {
	Row rows[MAX_Y_AXIS];
	initRows(rows);
	makeFrame(rows);
	system("cls");
	drawFrame(rows);
	notifyItems();
}

void Painter::initRows(Row* pRows) {
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		Row* pNewRow = new Row(MAX_X_AXIS);
		pRows[i] = *pNewRow;
	}
}

void Painter::makeFrame(Row* pRows) {
	for (int i = 0; i < totalItems; i++) {
		AbstractItem* pItem = pItems + i;
		Points* pPoints = pItem->getPoints();
		for (int j = 0; j < pPoints->noOfPoints; j++) {
			Point* pPoint = pPoints->pPointArray + j;
			if (isWithinBounds(*pPoint)) {
				Row* pRow = pRows + (pPoint->y);		
				bool* pPointFlag = (pRow->pPointFlags) + (pPoint->x);
				*(pPointFlag) = true;
				if(((pPoint->x) + 1)>(pRow->size)) {
					pRow->size = (pPoint->x) + 1;
				}
			}
		}
	}
}

bool Painter::isWithinBounds(Point point) {
	return (point.x < MAX_X_AXIS) && (point.x >= 0) && (point.y < MAX_Y_AXIS) && (point.y >= 0);
}

void Painter::drawFrame(Row* pRows) {
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		if (pRows[i].size > 0) {
			for (int j = 0; j < pRows[i].size; j++) {
				bool glow = *(pRows[i].pPointFlags + j);
				(glow == true) ? cout << "*" : cout << " ";
			}
		}
		cout << endl;
	}
}

void Painter::notifyItems() {
	for (int i = 0; i < totalItems; i++) {
		AbstractItem* pItem = pItems + i;
		pItem->onDraw();
	}
}