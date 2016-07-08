#pragma once

#include "Button.h"
#include "Panel.h"
#include "MouseListener.h"


class NumericBox2 : public Panel2, public MouseListener2
{
private:
	Label2 label;
	Button2 minus;
	Button2 plus;
	int currentValue;
	int min;
	int max;

	string convertToString(int num);
public:

	NumericBox2(int _width, int min, int _max);
	void mousePressed(Control* widget, int x, int y, bool isLeft);
	void setValue(int val) { currentValue = val; }
	int getCurrentValue()const { return currentValue; }


	//Acts on key event
	virtual void keyDown(KEY_EVENT_RECORD mouse) { Panel2::keyDown(mouse); }



	//Acts on mouse event
	virtual void mousePressed(int x, int y) { Panel2::mousePressed(x, y); };

	//Prints the widget to the screen
	//virtual void printWidget() const = 0;


};