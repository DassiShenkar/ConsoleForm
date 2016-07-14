#pragma once

#include "../Label/Label.h"
#include <iostream>
#include <vector>
#include "../MouseListener/MouseListener.h"

using namespace std;

class Button : public Label
{
private:
	vector<MouseListener *> listeners;

public:

	//Constructor
	Button(int _width = 10);

	//Acts on key event
	void keyDown(KEY_EVENT_RECORD key);

	//Acts on Mouse event
	void mousePressed(int x, int y, bool isLeft);

	//Adds a new listener
	void addMouseListener(MouseListener* _listener);


};