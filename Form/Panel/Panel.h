#pragma once
#include "../Control/Control.h"
#include <vector>
using namespace std;


class Panel : public Control
{
protected:
	vector<Control*> items;
	Control* panelControlInFocus;
	bool clickedOnWidget(int x, int y, Control*);


public:
	Panel(int _height = 50, int _width = 50);
	void addControl(Control& control, int x, int y);
	void keyDown(KEY_EVENT_RECORD key);
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics &g, int left, int top, int layer);
	void setStartPosition(int x, int y);
	void getAllControls(vector<Control*>* controls);
	vector<Control*> getItems() { return items; };
	void setPanelControlInFocus(Control* c) { panelControlInFocus = c; }
	Control* getPanelControlInFocus() const { return panelControlInFocus; }
};