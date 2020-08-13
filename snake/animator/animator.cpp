#include "animator.h"

Animator::Animator(Painter* pPainter) {
	this->pPainter = pPainter;
}

void Animator::render(int spaces) {
	pPainter->paint(spaces);
}