#pragma once
#include <iostream>
#include <string>
#include "WidgetDecorator.h"

using namespace std;

class BorderDecorator : public WidgetDecorator
{
private:
	string borderType;
public:
	BorderDecorator(Widget* wid, string type) : WidgetDecorator(wid), borderType(type) {}
	virtual void printWidget(COORD) const;
	string getBorderType() const { return borderType; }
	void setBorderType(string type) { borderType = type; }
};