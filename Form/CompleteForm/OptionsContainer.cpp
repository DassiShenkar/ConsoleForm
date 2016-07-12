#include "OptionsContainer.h"
#include "Button.h"
#include <iostream>
using namespace std;

OptionsContainer::OptionsContainer(int _height, int _width, vector<string> _items) : Panel(_height, _width)
{
	int row = 0;
	numberOfOptions = _items.size();
	for (vector<string>::iterator it = _items.begin(); it != _items.end(); it++)
	{
		Label* temp = new Label(_width);
		temp->setBorder(BorderType::None);
		temp->setText("o " + *it);
		addControl(*temp, 1, row++);
		temp->getLayer();
	}
	checked = new bool[_items.size()];
	for (int i = 0; i < numberOfOptions; i++)
	{
		checked[i] = false;
	}


}


void OptionsContainer::draw(Graphics &g, int left, int top, int layer)
{
	for (int i = 0; i < numberOfOptions; i++)
	{
		string temp = static_cast<Label*>(items[i])->getText();
		if (checked[i] == false)
			temp.replace(0, 1, "o");
		else
			temp.replace(0, 1, "x");
		static_cast<Label*>(items[i])->setText(temp);
	}

	Panel::draw(g, left, top, layer);
}




void OptionsContainer::setSelectedIndex(size_t index)
{
	for (int i = 0; i < numberOfOptions; i++)
	{
		checked[i] = false;
	}
	checked[index - 1] = true;
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