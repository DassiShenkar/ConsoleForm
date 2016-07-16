#include "../ComboBox/ComboBox.h"
#include <iostream>
#include <string>
using namespace std;

//A constructor that gets the starting coordinate of the Combo Box and the list of items
ComboBox::ComboBox(int _width, vector<string> _items) :OptionsContainer(_items.size(), _width, _items), drop_down(false)
{
	setHeight(1);
	setSelectedIndex(1);
	hideDropDown();
}

void ComboBox::mousePressed(Control* control, int x, int y, bool isLeft)
{
	setGlobalFocus(items[0]);
	if (control == items[0])
	{
		if (drop_down)
		{
			drop_down = false;
			setHeight(1);
			hideDropDown();
		}
		else
		{
			drop_down = true;
			setHeight(items.size());
			showDropDown();
		}
	}
	else
	{
		replaceHeader(control);
		drop_down = false;
		hideDropDown();
		setHeight(1);
	}
}



void ComboBox::replaceHeader(Control* c)
{
	string temp = static_cast<Button*>(items[0])->getText();
	static_cast<Button*>(items[0])->setText(static_cast<Button*>(c)->getText());
	static_cast<Button*>(c)->setText(temp);
	setSelectedIndex(1);
}




void ComboBox::getAllControls(vector<Control*>& controls)
{
	if (drop_down)
	{
		vector<Control*>::iterator it;
		for (it = items.begin(); it != items.end(); it++)
		{
			(*it)->getAllControls(controls);
		}
	}
	else
	{
		controls.push_back(items[0]);
	}
}

void ComboBox::hideDropDown()
{
	for (size_t i = 1; i < items.size(); i++)
	{
		items[i]->Hide();
	}
}

void ComboBox::showDropDown()
{
	for (size_t i = 1; i < items.size(); i++)
	{
		items[i]->Show();
	}
}