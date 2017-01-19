#pragma once
#include "ICanvasDrawable.h"

#include <string>
// ѕр€моугольник, обладающий координатами верхнего левого угла, шириной и высотой
class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(int x0, int y0, int width, int height);
	std::string GetType()const override;
	void Draw(ICanvas & canvas)const override;
	~CRectangle();
private:
	int m_x0;
	int m_y0;
	int m_width;
	int m_height;
};

