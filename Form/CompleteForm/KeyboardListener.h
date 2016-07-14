#pragma once

#include "Control.h"

//A struct that implements a listener
struct KeyboardListener
{

	//What happens on key Event
	virtual void buttonKeyDown(KEY_EVENT_RECORD key) = 0;
};