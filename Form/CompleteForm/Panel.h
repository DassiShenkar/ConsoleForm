#pragma once
#include "Widget.h"
#include <vector>
using namespace std;


class Panel : public Widget
{
private:
	vector<Widget*> items;
	Widget* focused;
	bool clickedOnWidget(MOUSE_EVENT_RECORD, Widget*);

public:
	Panel(int _width, int _height);
	void addControl(Widget* control, COORD position);
	void actOnKeyEvent(KEY_EVENT_RECORD key);
	void actOnMouseEvent(MOUSE_EVENT_RECORD mouse);
	void printWidget() const;
};