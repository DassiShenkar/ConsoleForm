#include "Panel.h"

Panel::Panel(int _width, int _height) : Widget(_width, _height), items(*new vector<Widget*>), focused(this)
{

}

void Panel::addControl(Widget* control, COORD position)
{
	items.push_back(control);
	control->setStartPosition({ position.X + startPos.X, position.Y + startPos.Y });
	
}

void Panel::setStartPosition(COORD position)
{
	vector<Widget*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		(*it)->setStartPosition({ position.X + (*it)->getStartPosition().X, position.Y + (*it)->getStartPosition().Y });
		(*it)->printWidget();
	}
	this->Widget::setStartPosition(position);
	printWidget();
}

void Panel::printWidget() const 
{
	if (isVisible)
	{
		printBorder();
		for (vector<Widget*>::const_iterator it = items.begin(); it != items.end(); it++)
			(*it)->printWidget();
	}
}

void Panel::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	if (focused == this)
		;
	else
	{
		focused->actOnKeyEvent(key);
	}
}

void Panel::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{

	bool flag = false;
	//Moves the focus to the appropriate widget
	for (vector<Widget*>::iterator it = items.begin(); it != items.end(); it++)
	{
		if (clickedOnWidget(mouse, *it))
		{
			flag = true;
			focused = *it;
			focused->actOnMouseEvent(mouse);
		}
	}

	//If the click is in the panel and not on any of its widgets set focused to this
	if (!flag && clickedOnWidget(mouse,this))		
		focused = this;
}

bool Panel::clickedOnWidget(MOUSE_EVENT_RECORD mouse, Widget* widget)
{
	//First need to find global
	if (mouse.dwButtonState == 0x0001 && mouse.dwMousePosition.X > widget->getStartPosition().X && mouse.dwMousePosition.X < widget->getEndPosition().X
		&& mouse.dwMousePosition.Y > widget->getStartPosition().Y && mouse.dwMousePosition.Y < widget->getEndPosition().Y)
		return true;
	return false;
}