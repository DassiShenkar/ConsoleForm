#include "Control.h"
#include <iostream>


using namespace std;

Control* Control::globalControlInFocus = 0;


void Control::Show()
{
	if (!isVisible)
		isVisible = true;
}

void Control::Hide()
{
	if (isVisible)
	{
		isVisible = false;
	}
}



//A method that determines what type of key was pressed
Keys Control::determineTypeOfKey(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown)
	{
		//Backspace
		if (key.wVirtualKeyCode == 8)
			return Keys::BACKSPACE;

		//Tab
		else if (key.wVirtualKeyCode == 9)
			return Keys::TAB;

		//Enter
		else if (key.wVirtualKeyCode == 13)
			return Keys::ENTER;

		//Spacebar
		else if (key.wVirtualKeyCode == 32)
			return Keys::SPACEBAR;

		//Left arrow
		else if (key.wVirtualKeyCode == 37)
			return Keys::LEFT;

		//Up arrow
		else if (key.wVirtualKeyCode == 38)
			return Keys::UP;

		//Right arrow
		else if (key.wVirtualKeyCode == 39)
			return Keys::RIGHT;

		//Down arrow
		else if (key.wVirtualKeyCode == 40)
			return Keys::DOWN;
		//Delete
		else if (key.wVirtualKeyCode == 46)
			return Keys::DEL;
		//Insert
		else if (key.wVirtualKeyCode == 45)
			return Keys::INSERT;

		//Anyother type of key
		else if ((key.wVirtualKeyCode >= 48 && key.wVirtualKeyCode <= 57) ||
			(key.wVirtualKeyCode >= 65 && key.wVirtualKeyCode <= 90) ||
			(key.wVirtualKeyCode >= 96 && key.wVirtualKeyCode <= 111) ||
			(key.wVirtualKeyCode >= 186 && key.wVirtualKeyCode <= 192) ||
			(key.wVirtualKeyCode >= 219 && key.wVirtualKeyCode <= 222))
		{
			return Keys::OTHER;
		}
	}
	return Keys::KEY_RELEASED;
}

void Control::printBorder(Graphics &g, int left, int top, int _layer)
{

	if (getLayer() != _layer)
		return;
	string frame_top = " ";
	string frame_side = " ";
	switch (border)
	{
	case BorderType::None:
		return;
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

	g.moveTo(getStartX(), getStartY());
	for (int i = 0; i < getWidth() + 1; i++)
	{
		g.write(frame_top);
	}

	//Prints the right and left boundaries
	for (int i = 0; i < getHeight(); i++)
	{
		int startX = getStartX();
		int startY = getStartY() + i + 1;
		g.moveTo(startX, startY);
		g.write(frame_side);


		short endX = getStartX() + width;
		short endY = getStartY() + i + 1;

		//Sets the consoleCursor position to the end
		g.moveTo(endX, endY);
		g.write(frame_side);

	}
	g.moveTo(getStartX(), getStartY() + (short)getHeight() + 1);
	for (int i = 0; i < width + 1; i++)
	{
		g.write(frame_top);
	}
}

string Control::convertToString(int val)
{
	string result = "";
	string temp = "";
	bool flag = false;
	if (val < 0)
	{
		flag = true;
		val = -val;
	}
	if (val == 0)
		return "0";
	while (val > 0)
	{

		temp.append(to_string(val % 10));
		val /= 10;
	}
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		if (flag)
		{
			result += "-";
			flag = false;
		}

		result += (temp.at(i));
	}
	return result;
}


Control::~Control() {}
