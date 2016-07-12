#pragma once
#include "Panel.h"
#include "Button.h"

class NumericBox : public Panel, public MouseListener
{
private:
	int value, min, max;
	Label text;
public:
	NumericBox(int width, int min, int max);

	virtual void buttonMousePressed(Control* control, int x, int y, bool isLeft);

	void setValue(int val);

	void addControl(Control& control, int x, int y) = delete;
};