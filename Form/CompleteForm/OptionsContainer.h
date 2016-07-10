#pragma once
#include "Panel2.h"
#include "Control.h"
#include "MouseListener2.h"

class OptionsContainer : public Panel2 , public MouseListener2
{
protected:
	
	bool* checked;
	void setAllOptionsToFalse();

public:
	OptionsContainer(int height, int _width, vector<string> _items);

	//A method that responds to key event
	void keyDown(KEY_EVENT_RECORD);

	//A method that responds to mouse event
	//virtual void mousePressed(int x, int y) { Panel2::mousePressed(x, y); };

	virtual void mousePressed(Control* widget, int x, int y, bool isLeft);

	void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	
};