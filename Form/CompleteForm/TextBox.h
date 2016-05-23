#pragma once

#include <Windows.h>
#include "Widget.h"
#include <iostream>
#include <wchar.h>
using namespace std;

class TextBox : public Widget
{
private:


	PWCHAR body;

	//Reprints the textbox as a response to a special key event
	void rePrintText(HANDLE&, Keys, int);

	/*A function that checks if the position of the console cursor
	is in the boundaries of the textBox
	*/
	bool isPositionLegal(COORD);


public:
	TextBox();
	TextBox(COORD, short, short);
	void setText(string text);
	string getText() const;

	



	//Implements the pure virtual functions of Widget
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);
	void printWidget() const;


	~TextBox() {  }


};
