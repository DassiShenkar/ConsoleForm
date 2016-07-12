#include "OptionsContainer.h"
#include "Label.h"
#include "Button.h"
#include <iostream>
using namespace std;

OptionsContainer::OptionsContainer(int _height, int _width, vector<string> _items) : Panel(_height, _width)
{


	int row = 0;
	for (vector<string>::iterator it = _items.begin(); it != _items.end(); it++)
	{
		Button* temp = new Button(_width - 1);
		temp->setText(*it);
		this->addControl(*temp, 0, row++);
	}
	checked = new bool[_items.size()];

	//Initializes the checked array to false
	setAllOptionsToFalse();

}



void OptionsContainer::buttonMousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setGlobalFocus(this);
	int picked = control->getStartY() - this->getStartY();
	setAllOptionsToFalse();
	checked[picked] = true;

}

void OptionsContainer::setAllOptionsToFalse()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		checked[i] = false;
	}
}


void OptionsContainer::setSelectedIndex(size_t index)
{

	checked[index] = true;
}

size_t OptionsContainer::getSelectedIndex() const
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (checked[i] == true)
			return i + 1;
	}
	return -1;
}


OptionsContainer::~OptionsContainer() 
{
	delete checked;
}