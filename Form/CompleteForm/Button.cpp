#pragma once
#include "Button.h"


Button2::Button2(int _width) : Control(2, _width), text(*(new Label2(_width))), listeners(*new vector<MouseListener2*>())
{
	text.setStartPosition(this->startPos);
}

void Button2::keyDown(KEY_EVENT_RECORD key)
{
	;
}

void Button2::mousePressed(int x, int y)
{
	vector<MouseListener2 *>::iterator it;
	for (it = listeners.begin(); it != listeners.end(); it++)
	{

		(*it)->mousePressed(this, x, y, true);

	}

}

void Button2::setStartPosition(COORD pos)
{
	text.setStartPosition(pos);
	Control::setStartPosition(pos);
}

void Button2::printWidget()
{
	text.printWidget();
}

void Button2::setText(string value)
{
	text.setText(value);

}

string Button2::getText() const
{
	return text.getText();
}

void Button2::addMouseListener(MouseListener2* _listener)
{
	listeners.push_back(_listener);
}

void Button2::draw(Graphics &g, int left, int top, int layer)
{
	text.draw(g, left, top, layer);
}

