#pragma once
#include "ICanvas.h"
#include <string>
class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas & canvas)const = 0;
	virtual std::string GetType()const = 0;
	virtual ~ICanvasDrawable() {};
};

