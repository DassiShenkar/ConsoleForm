#pragma once
#include "../OptionsContainer/OptionsContainer.h"
#include "../Button/Button.h"

#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

/*******************************************************************************
*A Class that implements a ComboBox control.								   *
*Listener methods Need to be implemented.									   *
*******************************************************************************/
class ComboBox : public OptionsContainer
{
private:
	size_t index;
	bool drop_down;					//indicates if drop down menu is down
	
public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string> options);


	void replaceHeader(Control* c);

	//Responds to the options Mouse events
	void mousePressed(Control* control, int x, int y, bool isLeft);

	void hideDropDown();
	
	void showDropDown();

	
	//Get the relevant controls for the TAB key
	void getAllControls(vector<Control*>& controls);

	
};