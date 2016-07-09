#pragma once

#include "Control.h"

struct MouseListener
{
	virtual void mousePressed(Control* control, int x, int y, bool isLeft) = 0;
};