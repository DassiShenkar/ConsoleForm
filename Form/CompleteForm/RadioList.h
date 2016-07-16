#pragma once

#include <iostream>
#include <Windows.h>
#include "OptionsContainer.h"
#include <vector>
#include <string>

using namespace std;


/*
A class that implements the Radio List Widget
*/
class RadioList : public OptionsContainer
{

public:

	//A constructor that recieves the starting coordinate and the list of items
	RadioList(int _height, int _width, vector<string>);

	void mousePressed(Control* control, int x, int y, bool isLeft) ;


};
