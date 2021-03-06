#include "OptionsContainer.h"
#include "../Button/Button.h"
#include <iostream>
using namespace std;

OptionsContainer::OptionsContainer(int _height, int _width, vector<string> _items) : Panel(_height, _width)
, mouseListeners(*new vector<MouseListener*>()), keyListeners(*new vector<KeyboardListener*>())
{
	int row = 0;
	numberOfOptions = _items.size();
	for (vector<string>::iterator it = _items.begin(); it != _items.end(); it++)
	{
		Button* temp = new Button(_width);
		temp->setBorder(BorderType::None);
		temp->setText("o " + *it);
		temp->setFocusable(true);
		temp->addListener(static_cast<MouseListener*>(this));
		temp->addListener(static_cast<KeyboardListener*>(this));
		addControl(*temp, 1, row++);
		temp->getLayer();
	}
	
	checked = new bool[_items.size()];
	for (int i = 0; i < numberOfOptions; i++)
	{
		checked[i] = false;
	}


}

void OptionsContainer::buttonKeyDown(KEY_EVENT_RECORD key)
{
	Keys k = determineTypeOfKey(key);
	Control* temp = getGlobalInFocus();
	size_t index = 0;
	for (index = 0; index < items.size(); index++)
	{
		if (items[index] == temp)
			break;
	}
	
	switch (k)
	{
	case  Keys::UP:
		if (index == 0)
			index = items.size();
		index--;
		setGlobalFocus(items[index]);
		break;
	case Keys::DOWN:
		if (index == items.size()-1)
			index = -1;
		index++;
		setGlobalFocus(items[index]);
		break;
	case Keys::ENTER:
		mousePressed(getGlobalInFocus(), getGlobalInFocus()->getStartX(), getGlobalInFocus()->getStartY() + 1, true);
	default:
		break;
	}
}


void OptionsContainer::draw(Graphics &g, int left, int top, int layer)
{
	for (int i = 0; i < numberOfOptions; i++)
	{
		string temp = static_cast<Button*>(items[i])->getText();
		if (checked[i] == false)
			temp.replace(0, 1, "o");
		else
		{
			temp.replace(0, 1, "x");
		}
		static_cast<Button*>(items[i])->setText(temp);
		
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
	return 1;
}

void OptionsContainer::addListener(MouseListener* _listener)
{
	mouseListeners.push_back(_listener);
}

void OptionsContainer::addListener(KeyboardListener* _listener)
{
	keyListeners.push_back(_listener);
}



OptionsContainer::~OptionsContainer()
{
	delete checked;
}