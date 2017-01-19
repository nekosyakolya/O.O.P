// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <memory>

#include "CCanvas.h"
#include "ICanvasDrawable.h"
#include "CRectangle.h"
#include "CTriangle.h"

using namespace std;


// Рисует картину picture на холсте canvas

void DrawTriangle()
{
	cout << "/\\" << endl;
	cout << "/ \\" << endl;
	cout << "/   \\" << endl;
}


void DrawRectangle()
{
	static const size_t SIZE = 3;
	for (size_t i = 0; i < SIZE; ++i)
	{
		cout << "|   |" << endl;
	}
	
}

void DrawPicture(ICanvas & canvas, const vector<shared_ptr<const ICanvasDrawable>> & picture)
{
	// Написать недостающий код

	for (auto pic : picture)
	{
		pic->Draw(canvas);
		cout << endl;
	}

	for (auto pic : picture)
	{
		if (pic->GetType() == "Rectangle")
		{
			DrawRectangle();
		}
		else if (pic->GetType() == "Triangle")
		{
			DrawTriangle();
		}
		cout << "-------" << endl;
	}

}

int main()
{
	try
	{
		vector<shared_ptr<const ICanvasDrawable>> picture;
		CCanvas canvas;


		CTriangle triangle(1, 2, 3, 4, 5, 6);
		picture.push_back(make_shared<const CTriangle>(triangle));

		CRectangle rectangle(1, 2, 3, 4);
		picture.push_back(make_shared<const CRectangle>(rectangle));

		DrawPicture(canvas, picture);
		
	}
	catch (invalid_argument const &e)
	{
		cout << e.what();
	}

	return EXIT_SUCCESS;
}

