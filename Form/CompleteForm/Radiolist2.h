#pragma once

#include <iostream>
#include <Windows.h>
#include "Control.h"
#include <vector>
#include <string>

using namespace std;


/*
A class that implements the Radio List Widget
*/
class RadioList2 : public Control
{
private:
	vector<string> item_list;				//A list that holds the items
	int checked;								//Holds the number of item that is chosen
	string convertToString(int num);
public:

	//A constructor that recieves the starting coordinate and the list of items
	RadioList2(int _height, int _width, vector<string>);

	//A method that responds to key event
	void keyDown(KEY_EVENT_RECORD);

	//A method that responds to mouse event
	void mousePressed(int x, int y);

	void printWidget();

	void draw(Graphics &g, int left, int top, int layer);

};
