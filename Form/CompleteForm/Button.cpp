#pragma once
#include "Button.h"

Button::Button(int _width) : Label(_width)
{

}

void Button::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

void Button::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	for (int i = 0; i < listeners.size(); i++) {
		listeners[i]->MousePressed(*this, mouse.dwMousePosition.X, mouse.dwMousePosition.Y, true);
	}
}

void Button::printWidget() const
{
	Label::printWidget();
}

void Button::setText(string value)
{
	Label::setText(value);
	printWidget();
}

string Button::getText() {
	return Label::getText();
}

void Button::addListener(MouseListener * listener)
{
	listeners.push_back(listener);
}