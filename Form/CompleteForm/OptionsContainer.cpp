#include "OptionsContainer.h"
#include "Label2.h"
#include "Button2.h"
#include <iostream>
using namespace std;

OptionsContainer::OptionsContainer(int _height, int _width, vector<string> _items) : Panel2(_height,_width)
{
	
	int row = 0;
	for (vector<string>::iterator it = _items.begin(); it != _items.end(); it++)
	{
		Button2* temp = new Button2(_width - 1);
		temp->setText(*it);
		this->addControl(*temp, 0, row++);
	}
	checked = new bool[_items.size()];

	//Initializes the checked array to false
	setAllOptionsToFalse();
	
}

void OptionsContainer::draw(Graphics &g, int left, int top, int layer)
{
	
	printBorder(g, left, top, layer);
	//Iterates through the item list and prints the items
	short i = 0;
	vector<Control*>::iterator it = items.begin();
	for (; it != items.end(); it++, i++)
	{
		g.moveTo(startPos.X + 1, startPos.Y + i + 1);
		if (checked[i] == true)
		{
			//White background and black font

			g.setBackground(Color::White);
			g.setForeground(Color::Black);


			g.write("X ");
			//g.write(convertToString(i + 1));
			//g.write(" ");
			g.write(static_cast<Button2*>(*it)->getText());

			//Restore original colors
			g.setBackground(Color::Black);
			g.setForeground(Color::White);
		}
		//Else if item is not picked
		else
		{
			g.write("O ");
		//	g.write(convertToString(i + 1));
			//g.write(" ");
			g.write(static_cast<Button2*>(*it)->getText());

			//Restore original colors
			g.setBackground(Color::Black);
			g.setForeground(Color::White);

		}
	}
	g.moveTo(startPos.X, startPos.Y + 2);
	g.setCursorVisibility(true);
}


void OptionsContainer::keyDown(KEY_EVENT_RECORD key)
{
	
}

void OptionsContainer::mousePressed(Control* control, int x, int y, bool isLeft)
{
	
	int picked = control->getStartPosition().Y - this->getStartPosition().Y;
	setAllOptionsToFalse();
	checked[picked] = true;

}

void OptionsContainer::setAllOptionsToFalse()
{
	for (int i = 0; i < items.size(); i++)
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
	for (int i = 0; i < items.size(); i++)
	{
		if (checked[i] == true)
			return i + 1;
	}
}


