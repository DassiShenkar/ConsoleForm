#pragma once
#include "Panel.h"
#include "Label.h"
#include "MouseListener.h"
#include "KeyboardListener.h"

/*******************************************************************************
*An Abstract Class that implements a OptionContainer.						   *
*Listener methods to be implemented											   *
*******************************************************************************/
class OptionsContainer : public Panel, public MouseListener, public KeyboardListener
{
protected:

	bool* checked;
	int clickedOption;
	int numberOfOptions;
	vector<MouseListener*> mouseListeners;
	vector<KeyboardListener*> keyListeners;


public:
	OptionsContainer(int height, int width, vector<string> _items);

	void keyDown(KEY_EVENT_RECORD key) ;

	virtual void mousePressed(int x, int y, bool isLeft) { Panel::mousePressed(x, y, isLeft); }

	void mousePressed(Control* control, int x, int y, bool isLeft) = 0;

	virtual void buttonKeyDown(KEY_EVENT_RECORD key) = 0;

	void addListener(MouseListener* _listener);

	//Adds a new listener
	void addListener(KeyboardListener* _listener);

	virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	int getSize() { return numberOfOptions; }

	~OptionsContainer();
};