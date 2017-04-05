#pragma once
#include "ICanvas.h"
#include <string>

struct Point
{
	int x;
	int y;
};

class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas & canvas)const = 0;
	virtual ~ICanvasDrawable() {};
};

