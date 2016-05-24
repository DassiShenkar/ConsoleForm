#pragma once

#include <iostream>
#include <Windows.h>
#include "Widget.h"
#include <vector>
#include <string>

using namespace std;


/*
A class that implements the Radio List Widget
*/
class RadioList : public Widget
{
private:
	vector<string>* item_list;				//A list that holds the items
	int checked;								//Holds the number of item that is chosen

public:

	//A constructor that recieves the starting coordinate and the list of items
	RadioList(int _width, int _height, vector<string>*);

	//A method that responds to key event
	void actOnKeyEvent(KEY_EVENT_RECORD);

	//A method that responds to mouse event
	void actOnMouseEvent(MOUSE_EVENT_RECORD);

	void printWidget() const;

};
