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
private:
	//Holds the number of item that is chosen
	string convertToString(int num);
public:

	//A constructor that recieves the starting coordinate and the list of items
	RadioList(int _height, int _width, vector<string>);

	//Acts on key event
	virtual void keyDown(KEY_EVENT_RECORD mouse) { Panel::keyDown(mouse); }



	//Acts on mouse event
	virtual void mousePressed(int x, int y) { Panel::mousePressed(x, y); }

	void addControl(Control& control, int x, int y) = delete;



	void printWidget() {};



};
