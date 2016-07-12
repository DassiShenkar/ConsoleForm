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
public:

	NumericBox(int _width, int min, int _max);
	void buttonMousePressed(Control* control, int x, int y, bool isLeft);
	void setValue(int val) { currentValue = val; }
	int getCurrentValue()const { return currentValue; }

	~NumericBox();
};