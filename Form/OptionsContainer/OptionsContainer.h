#pragma once
#include "../Panel/Panel.h"
#include "../Control/Control.h"
#include "../MouseListener/MouseListener.h"


class OptionsContainer : public Panel, public MouseListener
{
protected:

	bool* checked;
	void setAllOptionsToFalse();

public:
	OptionsContainer(int height, int _width, vector<string> _items);

	//A method that responds to key event
	void keyDown(KEY_EVENT_RECORD);

	virtual void buttonMousePressed(Control* widget, int x, int y, bool isLeft);

	void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;


};