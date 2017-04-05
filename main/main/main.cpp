// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <memory>

using namespace std;

// Рисует картину picture на холсте canvas


void DrawPicture(ICanvas & canvas, const vector<shared_ptr<const ICanvasDrawable>> & picture)
{
	// Написать недостающий код

	for (auto pic : picture)
	{
		pic->Draw(canvas);
		cout << endl;
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

		Point point = triangle.GetFirstPoint();
		
	}
	catch (invalid_argument const &e)
	{
		cout << e.what();
	}

	return EXIT_SUCCESS;
}

