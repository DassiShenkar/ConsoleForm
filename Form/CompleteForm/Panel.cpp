#include "Panel.h"

Panel::Panel(int _height, int _width) : Control(_height, _width), items(*new vector<Control*>), panelControlInFocus(this)
{
	this->setFocusable(false);
}

void Panel::addControl(Control& control, int x, int y)
{
	items.push_back(&control);
	control.setStartPosition(x + getStartX(), y + getStartY());
	control.setLayer(getLayer() + 1);

}

void Panel::setLayer(int l)
{
	Control::setLayer(l);
	vector<Control*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		(*it)->setLayer(getLayer() + 1);
	}

}

void Panel::setStartPosition(int x, int y)
{
	vector<Control*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		(*it)->setStartPosition((*it)->getStartX() + x, (*it)->getStartY() + y);
	}
	setStartX(getStartX() + x);
	setStartY(getStartY() + y);

}

void Panel::draw(Graphics &g, int left, int top, int _layer)
{

	if (isVisible)
	{
		if (layer == _layer)
			printBorder(g, left, top, _layer);
		else
		{
			for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
				(*it)->draw(g, (*it)->getStartX(), (*it)->getStartY(), _layer);
		}
	}
	if (getFocused()->getCursorVisibility() == true)
		g.moveTo(getFocused()->getCursorX(), getFocused()->getCursorY());
	else
		g.setCursorVisibility(false);
}

void Panel::keyDown(KEY_EVENT_RECORD key)
{
	Control::getFocused()->keyDown(key);

}

void Panel::mousePressed(int x, int y, bool isLeft)
{
	int _x = getFocused()->getStartX();
	int _y = getFocused()->getStartY();
	int _w = getFocused()->getWidth();
	int _h = getFocused()->getHeight();


	if (getFocused() != 0 && getFocused()!=this && isInside(x, y, _x,
		_y,_w, _h))
	{
		getFocused()->mousePressed(x, y, isLeft);
	}
	else
	{
		bool flag = false;
		
		//Moves the focus to the appropriate control
		for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
		{
			if (isInside(x, y, (*it)->getStartX(), (*it)->getStartY(), (*it)->getWidth(), (*it)->getHeight())&& flag==false)
			{
				flag = true;
				if ((*it)->canGetFocus())
				{
					
					Control::setFocus(*it);
					getFocused()->mousePressed(x, y, isLeft);
				}
				else
				{
					panelControlInFocus = *it;
					panelControlInFocus->mousePressed(x, y, isLeft);
				}
			}
		}

		//If the click is in the panel and not on any of its widgets set focused to this
		if (!flag && isInside(x, y, getStartX(), getStartY()+1, getWidth(), getHeight()))
		{
			//if (this->canGetFocus)
			panelControlInFocus = this;
			//Control::setGlobalFocus(this);
		}
	}
	
}


void Panel::getAllControls(vector<Control*>& controls)
{
	
	vector<Control*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		(*it)->getAllControls(controls);
	}
	controls.push_back(this);

}