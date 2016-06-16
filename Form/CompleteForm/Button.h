#pragma once
#include "Widget.h"
#include "Label.h"
#include <iostream>
#include <vector>
#include "MouseListener.h"

using namespace std;



class Button : public Widget
{
private:
	Label text;
	vector<MouseListener*> listeners;
	
public:

	//Constructor
	Button(int _width=10);

	//Sets the text of the button
	void setText(string value);

	//Acts on key event
	void actOnKeyEvent(KEY_EVENT_RECORD key);

	//Acts on Mouse event
	void actOnMouseEvent(MOUSE_EVENT_RECORD mouse);

	//Adds a new listener
	void addMouseListener(MouseListener* _listener);

	//Prints the button to the screen
	void printWidget() const;

	void setStartPosition(COORD pos);
	
};