#pragma once

#include <iostream>
#include <Windows.h>
#include "OptionsContainer.h"
#include <vector>
#include <string>

using namespace std;


/*
This is a class that implements the Check List Wigdet

*/
class CheckList : public OptionsContainer
{

public:

	//Constructor that recieves as parameters the starting coordinate and the items in a list
	CheckList(int height, int _width, vector<string>);

	//Acts on key event
	virtual void keyDown(KEY_EVENT_RECORD key) { Panel::keyDown(key); }

	//Acts on mouse event
	virtual void mousePressed(int x, int y) { Panel::mousePressed(x, y); };

	void addControl(Control& control, int x, int y) = delete;

	void mousePressed(Control* widget, int x, int y, bool isLeft);

	void selectIndex(size_t index);

	void deselectIndex(size_t index);

	void printWidget() {};

	~CheckList();


};

