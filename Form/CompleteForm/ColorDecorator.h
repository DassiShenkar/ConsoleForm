#pragma once
#include <string>
#include "WidgetDecorator.h"
using namespace std;

class ColorDecorator :public WidgetDecorator
{
private:
	string color;

public:
	ColorDecorator(Widget* wid, string _color) : WidgetDecorator(wid), color(_color) {}
	virtual void printWidget(COORD) const;
	string getColor() const { return color; }
	void setColor(string _color) { color = _color; }

};
