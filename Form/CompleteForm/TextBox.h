#pragma once

#include <Windows.h>
#include "Widget.h"
#include <iostream>
using namespace std;

class TextBox : public Widget
{
private:


	PWCHAR body;
	void rePrintText(HANDLE&, Keys, int);



public:
	TextBox();
	TextBox(COORD, short, short);
	//void printTextBox();



	//Implements the pure virtual functions of Widget
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);
	void printWidget() const;


	~TextBox() {  }


};
