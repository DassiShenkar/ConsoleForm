#pragma once

#include "Button.h"
#include "Panel.h"
#include "MouseListener.h"


class NumericBox : public Panel, public MouseListener
{
private:
	Label label;
	Button minus;
	Button plus;
	int currentValue;
	int min;
	int max;

	string convertToString(int num);
public:

	NumericBox(int _width, int min, int _max, int currentValue = 10);
	void actOnMouseClick(Widget* widget, MOUSE_EVENT_RECORD mouse);
	void setCurrentValue(int val) { currentValue = val; }
	int getCurrentValue()const { return currentValue; }
	
	/*
	//Acts on key event
	virtual void actOnKeyEvent(KEY_EVENT_RECORD) = 0;



	//Acts on mouse event
	virtual void actOnMouseEvent(MOUSE_EVENT_RECORD) = 0;

	//Prints the widget to the screen
	virtual void printWidget() const = 0;

	*/
};