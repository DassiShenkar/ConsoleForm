#include "ComboBox.h"
#include "RadioList.h"
#include <iostream>
#include <string>
using namespace std;

//A constructor that gets the starting coordinate of the Combo Box and the list of items
ComboBox::ComboBox(int _width, vector<string> _items) : Panel(1, _width), header(*new Button(_width))
, body(*new RadioList(_items.size(), _width, _items))
{
	header.setText(" o Select");
	body.setBorder(BorderType::None);

	header.addListener(static_cast<MouseListener*>(this));
	header.addListener(static_cast<KeyboardListener*>(this));
	
	body.addListener(static_cast<MouseListener*>(this));
	body.addListener(static_cast<KeyboardListener*>(this));
	Panel::addControl(header, 0, 0);
	Panel::addControl(body, 0, 1);
	body.Hide();


}

void ComboBox::mousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setGlobalFocus(&header);
	if (control == &header)
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

	else 
	{
		setSelectedIndex(y - body.getStartY());
		string temp = static_cast<Button*>(body.getItems()[body.getSelectedIndex()-1])->getText();
		temp.replace(0, 1, " x");
		header.setText(temp);
		mousePressed(&header, header.getStartX(), header.getStartY(), true);

	}
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (isInside(x, y, header.getStartX(), header.getStartY(), header.getWidth(), header.getHeight()))
		mousePressed(&header, x, y, isLeft);
	else
		mousePressed(&body, x, y, isLeft);

}

void ComboBox::buttonKeyDown(KEY_EVENT_RECORD key)
{
	mousePressed(getGlobalInFocus(), getGlobalInFocus()->getStartX(), getGlobalInFocus()->getStartY()+1, true);

}





void ComboBox::setSelectedIndex(size_t index)
{
	body.setSelectedIndex(index);
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
		controls.push_back(this);
	}
	else
	{
		controls.push_back(&header);
		drop_down = false;
	}
}