#pragma once
#include "OptionsContainer.h"
#include "Button.h"
#include "MouseListener.h"
#include <Windows.h>
#include <vector>
#include <string>
#include "KeyboardListener.h"
using namespace std;

/*******************************************************************************
*A Class that implements a ComboBox control.								   *
*Listener methods Need to be implemented.									   *
*******************************************************************************/
class ComboBox : public Panel, public MouseListener, public KeyboardListener
{
private:
	size_t index;
	bool drop_down;					//indicates if drop down menu is down
	Button header;					//The header as a button
	OptionsContainer& body;			//The drop_down menu - implemented as a RadioBox

public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string> options);

	//Delete the addControl method - The only way is to Use Panel::addControl
	void addControl(Control& control, int x, int y) = delete;

	//Acts on mouse right Click
	void mousePressed(int x, int y, bool isLeft);

	//Set the selected index to true 
	void setSelectedIndex(size_t i);

	//Responds to the options key events
	void buttonKeyDown(KEY_EVENT_RECORD key);

	//Responds to the options Mouse events
	void mousePressed(Control* control, int x, int y, bool isLeft);

	//Get the relevant controls for the TAB key
	void getAllControls(vector<Control*>& controls);

	
};