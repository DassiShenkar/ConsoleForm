#pragma once

#include <Windows.h>
#include "Widget.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;

class TextBox : public Widget
{
private:
	
	
	PWCHAR body;
	
	
	
	

public:
	TextBox();
	TextBox(COORD, short, short);
	
	

	//Implements the pure virtual functions of Widget
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);



	~TextBox() {  }


};
