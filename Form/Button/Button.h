#pragma once

#include "../Label/Label.h"
#include <iostream>
#include <vector>
//#include "../MouseListener/MouseListener.h"
//#include "../Listeners/KeyboardListener.h"
using namespace std;


/*******************************************************************************
*A Class that implements a Button control.									   *
*Listener methods Need to be implemented.									   *
*******************************************************************************/
class Button : public Label
{
private:
	vector<MouseListener*> mouseListeners;
	vector<KeyboardListener*> keyListeners;

public:

	//Constructor
	Button(int _width = 10);

	//Acts on key down event
	void keyDown(KEY_EVENT_RECORD key);

	//Acts on Mouse right click event
	void mousePressed(int x, int y, bool isLeft);

	void focusOut();

	//Adds a new listener
	void addListener(MouseListener* _listener);

	//Adds a new listener
	void addListener(KeyboardListener* _listener);




};