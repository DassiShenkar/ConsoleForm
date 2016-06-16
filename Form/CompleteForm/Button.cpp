#pragma once
#include "Button.h"


Button::Button(int _width) : Widget(_width, 3), text(*(new Label(_width))) , listeners(*new vector<MouseListener*>())
{
	text.setStartPosition(this->startPos);
}

void Button::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

void Button::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	vector<MouseListener*>::iterator it = listeners.begin();
	for (; it != listeners.end(); it++)
	{
		(*it)->actOnMouseClick(this, mouse);
	}

}

void Button::setStartPosition(COORD pos)
{
	text.setStartPosition(pos);
	Widget::setStartPosition(pos);
}

void Button::printWidget() const
{
	text.printWidget();
}

void Button::setText(string value)
{
	text.setText(value);
	printWidget();
}

void Button::addMouseListener(MouseListener* _listener)
{
	listeners.push_back(_listener);
}

