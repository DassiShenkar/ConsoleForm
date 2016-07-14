#pragma once

#include "Control.h"

struct MouseListener2
{
	virtual void mousePressed(Control* control, int x, int y, bool isLeft) = 0;
};