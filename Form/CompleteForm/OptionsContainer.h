#pragma once
#include "Panel.h"
#include "Control.h"
#include "MouseListener.h"

class OptionsContainer : public Panel, public MouseListener
{
protected:

	bool* checked;
	void setAllOptionsToFalse();

public:
	OptionsContainer(int height, int _width, vector<string> _items);

	//A method that responds to key event
	void keyDown(KEY_EVENT_RECORD);

	//A method that responds to mouse event
	virtual void mousePressed(int x, int y) = 0;

	virtual void mousePressed(Control* widget, int x, int y, bool isLeft);

	void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	~OptionsContainer();
};