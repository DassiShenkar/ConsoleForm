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


	//A method that responds to mouse event
	virtual void mousePressed(int x, int y, bool isLeft) {};

	virtual void buttonMousePressed(Control* control, int x, int y, bool isLeft);

	

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	~OptionsContainer();
};