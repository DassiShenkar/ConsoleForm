#include "CheckList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
CheckList::CheckList(int _height, int _width, vector<string> _items) : OptionsContainer(_height, _width, _items)
{

}

void CheckList::mousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setFocus(control);
	for (int i = 0; i < numberOfOptions; i++)
	{
		if (y - getStartY() - 1 == i)
			checked[i] = !checked[i];

	}
}

void CheckList::buttonKeyDown(KEY_EVENT_RECORD key)
{
	mousePressed(getFocused(), getFocused()->getStartX(), getFocused()->getStartY()+1, true);
}


void CheckList::selectIndex(size_t index)
{
	checked[index - 1] = true;
}

