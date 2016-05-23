#pragma once

#include <iostream>
#include <Windows.h>
#include "Widget.h"
#include <vector>
#include <string>

using namespace std;


/*
This is a class that implements the Check List Wigdet

*/
class CheckList : public Widget
{

private:

	vector<string>* item_list;			//A Linked List to hold the items of the Check List
	bool * checked;							//An array that keeps track if the item was picked

public:

	//Default Constructor that activates the Widget default construcotr
	CheckList();

	//Constructor that recieves as parameters the starting coordinate and the items in a list
	CheckList(COORD, vector<string>*);

	//A method that responds to a key event
	void actOnKeyEvent(KEY_EVENT_RECORD);

	//A method that responds to a mouse event
	void actOnMouseEvent(MOUSE_EVENT_RECORD);

	void printWidget() const;

};
#pragma once
