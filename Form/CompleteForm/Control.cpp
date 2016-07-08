#include "Control.h"
#include <iostream>


using namespace std;

Control* Control::focused = 0;


void Control::Show()
{
	if (isVisible)
		;
	else
	{
		isVisible = true;
		printWidget();
	}
}

void Control::Hide()
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
void Control::setBackground(BackgroundColor color)
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
void Control::setForeground(ForegroundColor color)
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
void Control::setBorder(BorderType _border)
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
Keys Control::determineTypeOfKey(KEY_EVENT_RECORD key)
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

void Control::printBorder(Graphics &g, int left, int top, int layer)
{


	string frame_top = " ";
	string frame_side = " ";
	switch (border)
	{
	case BorderType::None:
		break;
	case BorderType::Single:
		frame_top = "-";
		frame_side = "|";
		break;
	case BorderType::Double:
		frame_top = "\xcd";
		frame_side = "\xba";
		break;
	default:
		break;
	}

	g.moveTo(startPos.X, startPos.Y);
	for (int i = 0; i < getWidth() + 1; i++)
	{
		g.write(frame_top);
		//cout << frame_top;
	}

	//Prints the right and left boundaries
	for (int i = 0; i < height; i++)
	{
		short startX = startPos.X;
		short startY = startPos.Y + i + 1;
		g.moveTo(startX, startY);
		g.write(frame_side);
		//cout << frame_side;


		short endX = startPos.X + width;
		short endY = startPos.Y + i + 1;

		//Sets the consoleCursor position to the end
		g.moveTo(endX, endY);
		g.write(frame_side);
		//cout << frame_side;

	}
	g.moveTo(startPos.X, startPos.Y + (short)getHeight() + 1);
	for (int i = 0; i < width + 1; i++)
	{
		g.write(frame_top);
		//cout << frame_top;
	}




}

string Control::convertToString(int val)
{
	string result = "";
	string temp = "";
	if (val < 0)
	{
		temp.append("-");
		val = -val;
	}
	while (val > 0)
	{

		temp.append(to_string(val % 10));
		val /= 10;
	}
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		result += (temp.at(i));
	}
	return result;
}


Control::~Control() {}
