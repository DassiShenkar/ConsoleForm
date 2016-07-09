#pragma once
#include "Control.h"
#include "Label.h"
#include <iostream>
#include <vector>
#include "MouseListener.h"

using namespace std;


class MouseListener;
class Button : public Control
{
private:
	Label text;
	vector<MouseListener *> listeners;

public:

	//Constructor
	Button(int _width = 10);

	//Sets the text of the button
	void setText(string value);

	string getText() const;

	//Acts on key event
	void keyDown(KEY_EVENT_RECORD key);

	//Acts on Mouse event
	void mousePressed(int x, int y);

	//Adds a new listener
	void addMouseListener(MouseListener* _listener);

	//Prints the button to the screen
	void printWidget();

	void setStartPosition(COORD pos);

	virtual void draw(Graphics &g, int left, int top, int layer);

};