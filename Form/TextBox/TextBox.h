#pragma once

#include <Windows.h>
#include "../Button/Button.h"
#include "../KeyboardListener/KeyboardListener.h"
#include <iostream>
#include <wchar.h>
#include "../MouseListener/MouseListener.h"
using namespace std;

class TextBox : public Button, public MouseListener, public KeyboardListener
{
private:
	

public:
	TextBox(int _width);
	void keyDown(KEY_EVENT_RECORD key);
	void buttonKeyDown(KEY_EVENT_RECORD key) {};
	void mousePressed(Control* control, int x, int y, bool isLeft);
	void mousePressed(int x, int y, bool isLeft);
	void focusEvent();
	~TextBox() {  }


};
