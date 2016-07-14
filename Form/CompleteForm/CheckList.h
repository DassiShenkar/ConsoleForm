#pragma once

#include <iostream>
#include <Windows.h>
#include "OptionsContainer.h"
#include <vector>
#include <string>

using namespace std;

/*******************************************************************************
*A Class that implements a CheckList control.								   *
*Listener methods Need to be implemented.									   *
*******************************************************************************/
class CheckList : public OptionsContainer
{

public:

	//A constructor that recieves the starting coordinate and the list of items
	CheckList(int _height, int _width, vector<string>);

	//Acts on the option button key press
	void buttonKeyDown(KEY_EVENT_RECORD key);

	//Acts on the option button mouse click
	void mousePressed(Control* control, int x, int y, bool isLeft);

	//Sets the given option to checked
	void selectIndex(size_t index);


};
