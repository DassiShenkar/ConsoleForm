#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include "Widget.h"
using namespace std;

/*
A class that implements the Label Widget
*/
class Label : public Widget
{
private:

	string text;			//The label's text

public:

	//A default constructor that activates the default Widget constructor
	Label();

	//A constructor that recieves the starting coordinate
	Label(COORD, string);

	//A method that handles key events
	void actOnKeyEvent(KEY_EVENT_RECORD);

	//A method that handles mouse events
	void actOnMouseEvent(MOUSE_EVENT_RECORD);



};

