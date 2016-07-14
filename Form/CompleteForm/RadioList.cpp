#include "RadioList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
RadioList::RadioList(int _height, int _width, vector<string> _items) : OptionsContainer(_height, _width, _items)
{

}

void RadioList::mousePressed(Control* control, int x, int y, bool isLeft)
	{
	
	Control::setFocus(control);
	for (int i = 0; i < numberOfOptions; i++)
	{
		if (y - getStartY() - 1 == i)
			checked[i] = true;
		else
			checked[i] = false;

	}
}

//Deals with the key event sent from the option
void RadioList::buttonKeyDown(KEY_EVENT_RECORD key)
{
	Keys k = determineTypeOfKey(key);

	vector<KeyboardListener*>::iterator it;
		mousePressed(getFocused(), getFocused()->getStartX(), getFocused()->getStartY()+1, true);

}

