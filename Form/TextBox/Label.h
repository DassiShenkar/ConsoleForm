#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include "Widget.h"
using namespace std;

class Label: public Widget
{
private:
	
	string text;

public:
	Label();
	Label(COORD, string);
	Label(COORD, short,short, string);
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);
	


};

