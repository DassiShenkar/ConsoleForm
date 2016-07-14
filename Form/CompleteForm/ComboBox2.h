#pragma once
#include "Control.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

/*A class that implements a Combo Box Widget*/
class ComboBox2 : public Control
{
private:
	size_t index;
	vector<string> item_list;			//A list to hold the items of the Combo Box
	string header;							//The picked label
	bool drop_down;							//Indicates whether the drop down menu is open
	void clearLabel() const;						//A method to clear the header label
	void clearBody() const;						//Hides the drop down menu
	void clearBody(Graphics &g, int left, int top, int layer) const;
public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox2(int _width, vector<string> options);

	//Gets the header label
	string getHeader() const { return header; }

	//Sets the header label to a given string
	void setHeader(string _header) { header = _header; }


	//Method that responds to key events
	void keyDown(KEY_EVENT_RECORD);

	//Method that responds to mouse events
	void mousePressed(int x, int y);

	void printWidget();

	virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t i) { index = i; };

	size_t getSelectedIndex() const { return index; }
};
#pragma once
