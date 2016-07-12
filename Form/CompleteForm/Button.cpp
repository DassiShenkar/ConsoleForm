#pragma once
#include "Button.h"


Button::Button(int _width) : Label(_width), listeners(*new vector<MouseListener*>())
{
	setText("");
	setFocusable(true);
}

void Button::keyDown(KEY_EVENT_RECORD key)
{
	Keys k = determineTypeOfKey(key);
	vector<MouseListener*>::iterator it;
	if (k == Keys::ENTER)
		for (it = listeners.begin(); it != listeners.end(); it++)
		{

			(*it)->buttonMousePressed(this, getStartX(), getStartY(), true);

		}

}

void Button::mousePressed(int x, int y, bool isLeft)
{
	vector<MouseListener*>::iterator it;
	for (it = listeners.begin(); it != listeners.end(); it++)
	{

		(*it)->buttonMousePressed(this, x, y, true);

	}

}

void Button::addMouseListener(MouseListener* _listener)
{
	listeners.push_back(_listener);
}


