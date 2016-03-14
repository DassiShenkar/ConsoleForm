#pragma once

#include <Windows.h>
#include "Widget.h"
#include <iostream>
using namespace std;

class TextBox : public Widget
{
private:
	string content;


public:
	TextBox();
	TextBox(COORD, short, short);
	string getContent() { return content; }
	void setContent(string _content) { content = _content; }

	//Override Widget's 
	void setKeyEvent(KEY_EVENT_RECORD);
	void setMouseEvent(MOUSE_EVENT_RECORD);



	~TextBox() {}


};
