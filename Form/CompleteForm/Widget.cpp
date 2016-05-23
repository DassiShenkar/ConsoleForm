#include "Widget.h"
#include <iostream>


using namespace std;


//Sets the visibility of the widget
void Widget::setVisibility(bool visibility)
{
	//If there is no change is visibility - do nothing
	if (isVisible == visibility)
		;
	else
	{
		isVisible = visibility;		
		if (isVisible)				
			printWidget();
		else
			hideWidget();
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



Widget::~Widget() {}
