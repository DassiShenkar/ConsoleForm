#include "CheckList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;



//Constructor that recieves as parameters the starting coordinate and the items in a list 
CheckList::CheckList(int _height, int _width, vector<string> _items) : OptionsContainer(_height + 2, _width, _items)
{
	for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
	{
		static_cast<Button*>(*it)->addMouseListener(this);
	}

}


void CheckList::mousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setFocus(this);
	int i = control->getStartPosition().Y - this->getStartPosition().Y;
	checked[i] = !checked[i];
}

void CheckList::selectIndex(size_t index)
{

	checked[index] = true;
}

void CheckList::deselectIndex(size_t index)
{
	checked[index] = false;
}

CheckList::~CheckList()
{
}
