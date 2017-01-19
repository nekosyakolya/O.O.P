

#include "stdafx.h"

#include "CCanvas.h"

void CCanvas::DrawLine(int x0, int y0, int x1, int y1)
{
	std::cout << "DrawLine:(" << std::to_string(x0) << ", " << std::to_string(y0) << ") - (" <<
		std::to_string(x1) << ", " << std::to_string(y1) << ")" << std::endl;
}

CCanvas::~CCanvas()
{
}

