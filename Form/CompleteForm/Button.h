#pragma once
#include "Widget.h"
#include "Label.h"
#include <iostream>
#include <vector>
#include "Widget.h"

using namespace std;

typedef struct MouseListener {
	virtual void MousePressed(Widget &widget, int x, int y, bool isLeft) = 0;
} MouseListener;

class Button : public Label
{
private:
	vector<MouseListener*> listeners;
public:

	Button(int _width = 10);
	string getText();
	void setText(string value);
	void addListener(MouseListener *listener);
	void actOnKeyEvent(KEY_EVENT_RECORD key);
	void actOnMouseEvent(MOUSE_EVENT_RECORD mouse);
	void printWidget() const;
};