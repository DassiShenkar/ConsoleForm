#pragma once
#include "Control.h"
#include "Label.h"
#include <iostream>
#include <vector>
#include "MouseListener.h"

using namespace std;


class MouseListener2;
class Button2 : public Control
{
private:
	Label2 text;
	vector<MouseListener2 *> listeners;

public:

	//Constructor
	Button2(int _width = 10);

	//Sets the text of the button
	void setText(string value);

	string getText() const;

	//Acts on key event
	void keyDown(KEY_EVENT_RECORD key);

	//Acts on Mouse event
	void mousePressed(int x, int y);

	//Adds a new listener
	void addMouseListener(MouseListener2* _listener);

	//Prints the button to the screen
	void printWidget();

	void setStartPosition(COORD pos);

	virtual void draw(Graphics &g, int left, int top, int layer);

};