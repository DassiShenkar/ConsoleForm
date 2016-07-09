#pragma once
#include "Button.h"


Button::Button(int _width) : Control(2, _width), text(*(new Label(_width))), listeners(*new vector<MouseListener*>())
{
	text.setStartPosition(this->startPos);
}

void Button::keyDown(KEY_EVENT_RECORD key)
{
	;
}

void Button::mousePressed(int x, int y) {
	vector<MouseListener *>::iterator it;
	for (it = listeners.begin(); it != listeners.end(); it++) {
		(*it)->mousePressed(this, x, y, true);
	}
}


void Button::setStartPosition(COORD pos){
	text.setStartPosition(pos);
	Control::setStartPosition(pos);
}

void Button::printWidget()
{
	text.printWidget();
}

void Button::setText(string value)
{
	text.setText(value);

}

string Button::getText() const
{
	return text.getText();
}

void Button::addMouseListener(MouseListener* _listener)
{
	listeners.push_back(_listener);
}

void Button::draw(Graphics &g, int left, int top, int layer)
{
	text.draw(g, left, top, layer);
}

