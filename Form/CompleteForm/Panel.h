#pragma once
#include "Control.h"
#include <vector>
using namespace std;


class Panel : public Control
{
protected:
	vector<Control*> items;
	Control* controlInFocus;
	bool clickedOnWidget(int x, int y, Control*);
	int numberOfItems;

public:
	Panel(int _height = 50, int _width = 50);
	void addControl(Control& control, int x, int y);
	void keyDown(KEY_EVENT_RECORD key);
	void mousePressed(int x, int y);
	void printWidget();
	void draw(Graphics &g, int left, int top, int layer);
	void setStartPosition(COORD c);
	void getAllControls(vector<Control*>* controls);
	vector<Control*> getItems() { return items; };
	void setControlInFocus(Control* c) { controlInFocus = c; }
	Control* getControlInFocus() const { return controlInFocus; }
	~Panel();
};