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

	NumericBox(int _width, int min, int _max);
	void mousePressed(Control* widget, int x, int y, bool isLeft);
	void setValue(int val) { currentValue = val; }
	int getCurrentValue()const { return currentValue; }


	//Acts on key event
	virtual void keyDown(KEY_EVENT_RECORD mouse) { Panel::keyDown(mouse); }



	//Acts on mouse event
	virtual void mousePressed(int x, int y) { Panel::mousePressed(x, y); };

	//Prints the widget to the screen
	//virtual void printWidget() const = 0;

	~NumericBox();
};