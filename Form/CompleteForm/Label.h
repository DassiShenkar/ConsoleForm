#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include "Control.h"
using namespace std;

/*******************************************************************************
*A Class that implements a Label control.									   *
*******************************************************************************/
class Label : public Control
{
private:

	string text;			//The label's text

public:

	//A Constructor that recieves the length of the label as a parameter
	Label(int _width);

	//A method that handles key events
	virtual void keyDown(KEY_EVENT_RECORD);

	//A method that handles mouse events
	virtual void mousePressed(int x, int y, bool isLeft);

	//Sets the text of the Label
	virtual void setText(string _text);

	//Gets the text of the label
	string getText() const { return text; }

	//Draws the label on screen
	virtual void draw(Graphics &g, int left, int top, int layer);

	//Destructor
	virtual ~Label() {};

	




};

