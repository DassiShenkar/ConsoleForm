#pragma once

#include "Control.h"

//A struct that implements a listener
struct MouseListener
{
	//What heppens on mouse press
	virtual void mousePressed(Control* control, int x, int y, bool isLeft) = 0;

};