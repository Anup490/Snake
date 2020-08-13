#pragma once
#include "../painter/painter.h"

class Animator {
	unsigned short second = 0;
	Painter* pPainter;
public:
	Animator(Painter* pPainter);
	void render(int spaces);
};