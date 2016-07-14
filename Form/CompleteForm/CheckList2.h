#pragma once

#include <iostream>
#include <Windows.h>
#include "Control.h"
#include <vector>
#include <string>

using namespace std;


/*
This is a class that implements the Check List Wigdet

*/
class CheckList2 : public Control
{

private:

	vector<string> item_list;			//A Linked List to hold the items of the Check List
	bool * checked;							//An array that keeps track if the item was picked

public:

	//Constructor that recieves as parameters the starting coordinate and the items in a list
	CheckList2(int height, int _width, vector<string>);

	//A method that responds to a key event
	void keyDown(KEY_EVENT_RECORD key);

	//A method that responds to a mouse event
	void mousePressed(int x, int y);

	void selectIndex(size_t index);

	void deselectIndex(size_t index);

	void printWidget();

	virtual void draw(Graphics &g, int left, int top, int layer);

};

