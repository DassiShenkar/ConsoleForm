#include "ComboBox.h"
#include <iostream>
#include <string>
using namespace std;

//A constructor that gets the starting coordinate of the Combo Box and the list of items
ComboBox::ComboBox(int _width, vector<string> _items) : Panel(1, _width), header(*new Label(_width))
, body(_items.size(), _width, _items)
{
	header.setText(" o Select");
	Panel::addControl(header, 0, 0);
	Panel::addControl(body, 0, 1);
	body.Hide();


}



void ComboBox::setSelectedIndex(size_t index)
{
	body.setSelectedIndex(index);
}


void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (y - getStartY() - 1 == 0)
	{
		if (!drop_down)
		{
			body.Show();
			setHeight(2 + body.getSize());
			drop_down = true;
		}
		else
		{
			body.Hide();
			setHeight(1);
			drop_down = false;
		}
	}
	else if (drop_down)
	{
		setSelectedIndex(y - body.getStartY());
		string temp = static_cast<Label*>(body.getItems()[body.getSelectedIndex() - 1])->getText();
		temp.replace(0, 1, " o");
		header.setText(temp);
		setHeight(1);
		body.Hide();
		drop_down = false;
	}

}
