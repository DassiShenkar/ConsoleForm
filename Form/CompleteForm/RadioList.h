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

	//A default constructor that activates Widget default constructor
	RadioList();

	//A constructor that recieves the starting coordinate and the list of items
	RadioList(COORD, vector<string>*);

	//A method that responds to key event
	void actOnKeyEvent(KEY_EVENT_RECORD);

	//A method that responds to mouse event
	void actOnMouseEvent(MOUSE_EVENT_RECORD);

	//Prints the Radio List
	void printRadioList() const;

	void printWidget(COORD startPos) const { ; }

};
