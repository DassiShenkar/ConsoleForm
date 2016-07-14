#pragma once
#include "Button.h"


Button::Button(int _width) : Label(_width), mouseListeners(*new vector<MouseListener*>()), keyListeners(*new vector<KeyboardListener*>())
{
	setText("");
	setFocusable(true);
}

void Button::keyDown(KEY_EVENT_RECORD key)
{
	Keys k = determineTypeOfKey(key);
	vector<KeyboardListener*>::iterator it;
	if (k == Keys::ENTER)
		for (it = keyListeners.begin(); it != keyListeners.end(); it++)
		{

			(*it)->buttonKeyDown(key);

		}

}

void Button::mousePressed(int x, int y, bool isLeft)
{
	vector<MouseListener*>::iterator it;
	for (it = mouseListeners.begin(); it != mouseListeners.end(); it++)
	{

		(*it)->mousePressed(this, x, y, true);

	}

}

void Button::addListener(MouseListener* _listener)
{
	mouseListeners.push_back(_listener);
}

void Button::addListener(KeyboardListener* _listener)
{
	keyListeners.push_back(_listener);
}


