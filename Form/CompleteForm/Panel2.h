#pragma once
#include "Control.h"
#include <vector>
using namespace std;


class Panel2 : public Control
{
private:
	vector<Control*> items;
	Control* focused;
	bool clickedOnWidget(int x, int y, Control*);

public:
	Panel2(int _width=50, int _height=50);
	void addControl(Control& control, int x, int y);
	void keyDown(KEY_EVENT_RECORD key);
	//void mousePressed(MOUSE_EVENT_RECORD mouse);
	void mousePressed(int x, int y);
	void printWidget() ;
	void draw(Graphics &g, int left, int top, int layer);
	void setStartPosition(COORD c);
	void getAllControls(vector<Control*>* controls);
};