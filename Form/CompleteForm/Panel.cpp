#include "Panel.h"

Panel::Panel(int _height, int _width) : Control(_height, _width), items(*new vector<Control*>), controlInFocus(this)
{

}

void Panel::addControl(Control& control, int x, int y)
{
	items.push_back(&control);
	control.setStartPosition(x + getStartX(), y + getStartY());
	numberOfItems++;
}

void Panel::setStartPosition(COORD position)
{
	vector<Control*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		(*it)->setStartPosition(position.X + (*it)->getStartX(), position.Y + (*it)->getStartY());

	}
	this->Control::setStartPosition(position.X, position.Y);

}



void Panel::draw(Graphics &g, int left, int top, int layer)
{
	if (isVisible)
	{
		printBorder(g, left, top, layer);
		for (vector<Control*>::const_iterator it = items.begin(); it != items.end(); it++)
		{
			(*it)->printBorder(g, (*it)->getStartX(), (*it)->getStartY(), layer);
			(*it)->draw(g, (*it)->getStartX(), (*it)->getStartY(), layer);
		}
	}

}

void Panel::keyDown(KEY_EVENT_RECORD key)
{
	if (controlInFocus == this)
		;
	else
	{
		controlInFocus->keyDown(key);
	}
}



void Panel::mousePressed(int x, int y, bool isLeft)
{

	bool flag = false;
	//Moves the focus to the appropriate widget
	for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
	{
		if (clickedOnWidget(x, y, *it))
		{
			flag = true;
			controlInFocus = *it;
			controlInFocus->mousePressed(x, y, isLeft);
		}
	}

	//If the click is in the panel and not on any of its widgets set focused to this
	if (!flag && clickedOnWidget(x, y, this))
		controlInFocus = this;
}


bool Panel::clickedOnWidget(int x, int y, Control* widget)
{
	//First need to find global
	if (x > widget->getStartX() && x < widget->getStartX()+ getWidth()
		&& y > widget->getStartY() && y < widget->getStartY()+ getHeight())
		return true;
	return false;
}

void Panel::getAllControls(vector<Control*>* controls)
{
	vector<Control*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		controls->push_back(*(it));
	}

}

Panel::~Panel() {
	
}