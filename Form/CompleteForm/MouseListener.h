#pragma once

#include "Control.h"

struct MouseListener
{
	virtual void buttonMousePressed(Control* control, int x, int y, bool isLeft) = 0;
};