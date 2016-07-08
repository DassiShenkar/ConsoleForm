#pragma once

#include <Windows.h>
#include "Control.h"
#include <iostream>
#include <wchar.h>
using namespace std;

class TextBox2 : public Control
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
	TextBox2(int _width);
	TextBox2(int _height, int _width);
	void setText(string text);
	string getText() const;





	//Implements the pure virtual functions of Widget
	void keyDown(KEY_EVENT_RECORD key);
	void mousePressed(int x, int y);
	void printWidget();

	virtual void draw(Graphics &g, int left, int top, int layer) {}

	~TextBox2() {  }


};
