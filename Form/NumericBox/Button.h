#pragma once
#include "Label.h"

class Button : public Label
{
public:
	virtual void actOnMouseEvent(MOUSE_EVENT_RECORD);
};