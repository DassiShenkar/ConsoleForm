#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../KeyboardListener/KeyboardListener.h"
#include "../MouseListener/Mouselistener.h"

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

	void mousePressed(Control* control, int x, int y, bool isLeft) = 0;

	virtual void buttonKeyDown(KEY_EVENT_RECORD key);

	void addListener(MouseListener* _listener);

	void addListener(KeyboardListener* _listener);

	void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	int getSize() { return numberOfOptions; }

	~OptionsContainer();
};