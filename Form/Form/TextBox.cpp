#include "TextBox.h"

#include <iostream>

TextBox::TextBox() : startPos({ 20,10 }), width(20), height(20)
{

}

TextBox::TextBox(COORD pos, int width, int height) : startPos(pos), width(20), height(10)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hout, startPos);
	for (int i = 0; i < width; i++)
	{
		printf("\xcd");
	}
	for (int i = 0; i < height; i++)
	{

		printf("\n");
		short startX = pos.X;
		short startY = pos.Y + i;
		SetConsoleCursorPosition(hout, { startX,startY });
		printf("\xba");
		if (i == height - 1)
		{
			for (int i = 0; i < width; i++)
			{
				printf("\xcd");
			}
		}
		short endX = pos.X + width;
		short endY = pos.Y + i;
		SetConsoleCursorPosition(hout, { endX,endY });
		printf("\xba");
	}
}