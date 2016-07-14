#pragma once
#include "Panel.h"
#include "Button.h"
#include "KeyboardListener.h"

/*******************************************************************************
*A Class that implements a NumericBox control.								   *
*Listener methods to be implemented										       *
*******************************************************************************/
class NumericBox : public Panel, public MouseListener, public KeyboardListener
{
private:
	int value, min, max;
	Label text;
public:
	NumericBox(int width, int min, int max);

	virtual void buttonKeyDown(KEY_EVENT_RECORD key);

	virtual void mousePressed(Control* control, int x, int y, bool isLeft);

	void setValue(int val);

	void addControl(Control& control, int x, int y) = delete;
};