#pragma once
#include "Widget.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

/*A class that implements a Combo Box Widget*/
class ComboBox : public Widget
{
private:

	vector<string> item_list;			//A list to hold the items of the Combo Box
	string header;							//The picked label
	bool drop_down;							//Indicates whether the drop down menu is open
	void clearLabel() const;						//A method to clear the header label
	void clearBody() const;						//Hides the drop down menu
public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string>);

	//Gets the header label
	string getHeader() const { return header; }

	//Sets the header label to a given string
	void setHeader(string _header) { header = _header; }


	//Method that responds to key events
	void actOnKeyEvent(KEY_EVENT_RECORD);

	//Method that responds to mouse events
	void actOnMouseEvent(MOUSE_EVENT_RECORD);

	void printWidget() const;
};
#pragma once
