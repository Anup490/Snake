#include "painter.h"

Painter::Painter(initializer_list<AbstractItem*>* pItems) {
	this->pItems = pItems;
}

int Painter::paint() {
	int totalDotsDrawn = 0;
	Row rows[MAX_Y_AXIS];
	initRows(rows);
	makeFrame(rows);
	system("cls");
	drawFrame(rows, totalDotsDrawn);
	notifyItems();
	return totalDotsDrawn;
}

void Painter::initRows(Row* pRows) {
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		Row* pNewRow = new Row(MAX_X_AXIS);
		pRows[i] = *pNewRow;
	}
}

void Painter::makeFrame(Row* pRows) {
	for (AbstractItem* pItem : *pItems) {
		vector<Point*>* pPoints = pItem->getPoints();
		for (Point* pPoint : *pPoints) {
			if (isWithinBounds(*pPoint)) {
				Row* pRow = pRows + (pPoint->y);
				bool* pPointFlag = (pRow->pPointFlags) + (pPoint->x);
				*(pPointFlag) = true;
				if (((pPoint->x) + 1) > (pRow->size)) {
					pRow->size = (pPoint->x) + 1;
				}
			}
		}
	}
}

bool Painter::isWithinBounds(Point point) {
	return (point.x < MAX_X_AXIS) && (point.x >= 0) && (point.y < MAX_Y_AXIS) && (point.y >= 0);
}

void Painter::drawFrame(Row* pRows, int& rTotalDotsDrawn) {
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		for (int j = 0; j < pRows[i].size; j++) {
			bool glow = *(pRows[i].pPointFlags + j);
			if (glow == true) {
				cout << "*";
				rTotalDotsDrawn++;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < MAX_X_AXIS;i++) {
		cout << "=";
	}
}

void Painter::notifyItems() {
	for (AbstractItem* pItem : *pItems) {
		pItem->onDraw();
	}
}