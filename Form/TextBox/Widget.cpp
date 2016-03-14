#include "Widget.h"
#include <iostream>


using namespace std;

//Prints the wigdet to the screen
void Widget::PrintWidget(COORD pos)
{
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
		//printf("Click on the text box to start typing ");
	}
}


/*A function that checks if the position of the console cursor
is in the boundaries of the textBox
*/
bool Widget::isPositionLegal(COORD pos)
{
	if ((pos.X > this->getStartPosition().X && pos.X<this->getEndPosition().X) &&
		(pos.Y>this->getStartPosition().Y && pos.Y < this->getEndPosition().Y)
		)
		return true;

	return false;
}

//A method that determines what type of key was pressed
Keys Widget::determineTypeOfKey(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown)
	{
		if (key.wVirtualKeyCode == 8)
			return BACKSPACE;
		else if (key.wVirtualKeyCode == 9)
			return TAB;
		else if (key.wVirtualKeyCode == 13)
			return DOWN;
		else if (key.wVirtualKeyCode == 37)
			return LEFT;
		else if (key.wVirtualKeyCode == 38)
			return UP;
		else if (key.wVirtualKeyCode == 39)
			return RIGHT;
		else if (key.wVirtualKeyCode == 40)
			return DOWN;

		else return OTHER;
	}
	return KEY_RELEASED;
}



Widget::~Widget() {}
