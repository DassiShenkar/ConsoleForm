#pragma once
#include "Button.h"


Button::Button(int _width) : Widget(_width, 3), text(*(new Label(_width)))
{

}

void Button::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

void Button::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{

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