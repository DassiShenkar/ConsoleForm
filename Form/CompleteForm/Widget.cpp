#include "Widget.h"
#include <iostream>


using namespace std;


void Widget::Show()
{
	if (isVisible)
		;
	else
	{
		isVisible = true;
		printWidget();
	}
}

void Widget::Hide()
{
	if (isVisible)
	{
		isVisible = false;
		printWidget();
	}

	else
	{
		;
	}
}

//Sets the background color of the Widget
void Widget::setBackground(BackgroundColor color)
{
	if (background == color)
		;
	else
	{
		background = color;
		printWidget();
	}
}

//Sets the foreground color of the Widget
void Widget::setForeground(ForegroundColor color)
{
	if (foreground == color)
		;
	else
	{
		foreground = color;
		printWidget();
	}
}

//Sets the border type
void Widget::setBorder(BorderType _border)
{
	if (border == _border)
		;
	else
	{
		border = _border;
		printWidget();
	}
}



//A method that determines what type of key was pressed
Keys Widget::determineTypeOfKey(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown)
	{
		//Backspace
		if (key.wVirtualKeyCode == 8)
			return BACKSPACE;

		//Tab
		else if (key.wVirtualKeyCode == 9)
			return TAB;

		//Enter
		else if (key.wVirtualKeyCode == 13)
			return ENTER;

		//Spacebar
		else if (key.wVirtualKeyCode == 32)
			return SPACEBAR;

		//Left arrow
		else if (key.wVirtualKeyCode == 37)
			return LEFT;

		//Up arrow
		else if (key.wVirtualKeyCode == 38)
			return UP;

		//Right arrow
		else if (key.wVirtualKeyCode == 39)
			return RIGHT;

		//Down arrow
		else if (key.wVirtualKeyCode == 40)
			return DOWN;
		//Delete
		else if (key.wVirtualKeyCode == 46)
			return DEL;
		//Insert
		else if (key.wVirtualKeyCode == 45)
			return INSERT;

		//Anyother type of key
		else if ((key.wVirtualKeyCode >= 48 && key.wVirtualKeyCode <= 57) ||
			(key.wVirtualKeyCode >= 65 && key.wVirtualKeyCode <= 90) ||
			(key.wVirtualKeyCode >= 96 && key.wVirtualKeyCode <= 111) ||
			(key.wVirtualKeyCode >= 186 && key.wVirtualKeyCode <= 192) ||
			(key.wVirtualKeyCode >= 219 && key.wVirtualKeyCode <= 222))
		{
			return OTHER;
		}
	}
	return KEY_RELEASED;
}

void Widget::printBorder() const
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(hout, &cursor_info);

	WORD originalColors = ConsoleInfo->wAttributes;
	CONSOLE_CURSOR_INFO console;


	char frame_top = ' ';
	char frame_side = ' ';
	switch (border)
	{
	case BorderType::None:
		break;
	case BorderType::Single:
		frame_top = '-';
		frame_side = '|';
		break;
	case BorderType::Double:
		frame_top = '\xcd';
		frame_side = '\xba';
		break;
	default:
		break;
	}

	SetConsoleCursorPosition(hout, startPos);
	for (int i = 0; i < getWidth()+1; i++)
	{
		cout << frame_top;
	}

	//Prints the right and left boundaries
	for (int i = 0; i < height-1; i++)
	{
		short startX = startPos.X;
		short startY = startPos.Y + i+1;
		SetConsoleCursorPosition(hout, { startX,startY });
		cout << frame_side;


		short endX = startPos.X + width;
		short endY = startPos.Y + i+1;

		//Sets the consoleCursor position to the end
		SetConsoleCursorPosition(hout, { endX,endY });
		cout << frame_side;

	}
	SetConsoleCursorPosition(hout, { startPos.X ,startPos.Y + (short)getHeight()-1 });
	for (int i = 0; i < width+1; i++)
	{
		cout << frame_top;
	}


	

}

Widget::~Widget() {}
