#pragma once
#include "Control.h"
#include <vector>
using namespace std;


class Panel : public Control
{
protected:
	vector<Control*> items;
	Control* panelControlInFocus;

public:
	Panel(int _width = 50, int _height = 50);
	void addControl(Control& control, int x, int y);
	virtual void keyDown(KEY_EVENT_RECORD key);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void draw(Graphics &g, int left, int top, int layer);
	void setLayer(int l);
	void setStartPosition(int x, int y);
	virtual void getAllControls(vector<Control*>& controls);
	vector<Control*> getItems() { return items; }
};