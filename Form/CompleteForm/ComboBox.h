#pragma once
#include "Radiolist.h"
#include "Button.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

/*A class that implements a Combo Box Widget*/
/*
class ComboBox : public Panel, public MouseListener
{
private:
	size_t index;
	bool drop_down;
	void clearLabel(Graphics &g, int left, int top, int layer) const;
	void clearBody(Graphics &g, int left, int top, int layer) const;
public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string> options);

	//Method that responds to key events
	void keyDown(KEY_EVENT_RECORD key) { Panel::keyDown(key); }

	//Method that responds to mouse events
	void mousePressed(int x, int y) { Panel::mousePressed(x, y); }

	virtual void mousePressed(Control* widget, int x, int y, bool isLeft);

	void printWidget() {};

	void addControl(Control& control, int x, int y) = delete;

	virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t i) { index = i; };

	size_t getSelectedIndex() const { return index; }

	~ComboBox();
};
#pragma once
*/