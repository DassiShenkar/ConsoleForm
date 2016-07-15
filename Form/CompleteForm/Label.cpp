#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;


Label::Label(int _width) : Control(1, _width)
{
	setFocusable(false);
}

/*Label::~Label() 
{
	free(this);
}*/

//The label does not respond to any key event
void Label::keyDown(KEY_EVENT_RECORD key)
{
	;
}

//The label does not respond to any mouse event
void Label::mousePressed(int x, int y, bool isLeft)
{
	;
}


void Label::setText(string _text)
{
	if (_text.size() > getWidth())
		return;
	text = _text;
}


void Label::draw(Graphics &g, int left, int top, int _layer)
{
	if (isVisible&& getLayer() == _layer)
	{
		printBorder(g, left, top, _layer);
		g.moveTo(getStartX() + 1, getStartY() + 1);
		g.write(text);
		g.setForeground(Color::White);
	}

}

