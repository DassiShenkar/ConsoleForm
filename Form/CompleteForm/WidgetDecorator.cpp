#include <iostream>
#include "WidgetDecorator.h"

using namespace std;


//Prints the default wigdet to the screen
void WidgetDecorator::printWidget(COORD) const
{
	/*
	COORD  pos = this->getStartPosition();
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Set cursor to top left corner of text box
	SetConsoleCursorPosition(hout, startPos);



	//Prints the top boundary
	for (int i = 0; i < width; i++)
	{
		printf("\xcd");
	}

	//Prints the right and left boundaries
	for (int i = 0; i < height; i++)
	{

		printf("\n");
		short startX = pos.X;
		short startY = pos.Y + i;
		SetConsoleCursorPosition(hout, { startX,startY });
		printf("\xba");

		//Prints the bootom boundary
		if (i == height - 1)
		{
			for (int i = 0; i < width; i++)
			{
				printf("\xcd");
			}
		}


		short endX = pos.X + width;
		short endY = pos.Y + i;

		//Sets the consoleCursor position to the end
		SetConsoleCursorPosition(hout, { endX,endY });
		printf("\xba");

		SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });
		
	}*/
}