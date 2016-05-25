#pragma once
#include "Widget.h"
#include "Label.h"
#include <iostream>
using namespace std;

class Button : public Widget
{
private:
	Label text;

public:
	Button(int _width=10);
	void setText(string value);
	void actOnKeyEvent(KEY_EVENT_RECORD key);
	void actOnMouseEvent(MOUSE_EVENT_RECORD mouse);
	void printWidget() const;
};