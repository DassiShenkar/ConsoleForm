#include "RadioList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
RadioList::RadioList(int _height, int _width, vector<string> _items) : OptionsContainer(_height + 2, _width, _items)
{
	for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
	{
		static_cast<Button*>(*it)->addMouseListener(this);
	}
}




