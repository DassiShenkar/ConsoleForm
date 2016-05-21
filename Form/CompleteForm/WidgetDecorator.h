#pragma once
#include "Widget.h"
class WidgetDecorator : public Widget
{
protected:
	Widget* widget;

public:
	WidgetDecorator(Widget* wid) : widget(wid) {}
	virtual void printWidget(COORD startPos) const;


};
