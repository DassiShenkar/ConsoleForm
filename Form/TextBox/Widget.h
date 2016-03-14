#pragma once
#include <Windows.h>
#include "Keys.h"

class Widget
{
protected:
	//Starting coordinate for the Widget
	COORD startPos;

	//End coordinate for the Widget
	COORD endPos;

	//The dimensions
	short width, height;

	//The key event that is sent from ConsoleHandler
	KEY_EVENT_RECORD key_input;

	//The mouse event that is sent from ConsoleHandler
	MOUSE_EVENT_RECORD mouse_input;

	/*A function that checks if the position of the console cursor
	is in the boundaries of the textBox
	*/
	bool isPositionLegal(COORD);

	//A function that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);


public:

	//Default widget Constructor parameters
	Widget() : startPos{ 0,0 }, endPos({ width,height}), width(20), height(10) {}

	//Constructor with parameters
	Widget(COORD start, short _width, short _height) : startPos(start), width(_width), height(_height),
		endPos({ startPos.X + _width,startPos.Y + _height }) {}

	//Prints the wigdet to the screen
	virtual void PrintWidget(COORD);

	//Returns the width 
	virtual short getWidth() const { return width; }

	//Returns the height
	virtual short getHeight() const { return height; }

	//Sets the width
	virtual void setWidth(short _width) { width = _width; }

	//Sets the height
	virtual void setHeight(short _height) { height = _height; }

	//Sets the starting coordinate
	virtual void setStartPosition(COORD start) { startPos = start; }

	//Returns the starting coordinate
	virtual COORD getStartPosition() const { return startPos; }

	//Returns the end coordinate
	virtual COORD getEndPosition() const { return endPos; }

	//Sets the end coordinate
	virtual void setEndPosition(COORD end) { endPos = end; }

	//Gets the key event
	virtual KEY_EVENT_RECORD getKeyEvent() const { return key_input; }

	/*
		Acts on key event
		Each widget should implement the function.
		It responds to the key event sent by the ConsoleHandler
		(only for press down)
	*/
	virtual void actOnKetEvent(KEY_EVENT_RECORD) = 0;

	
	virtual MOUSE_EVENT_RECORD getMouseEvent() const { return mouse_input; }

	/*
		Acts on mouse event
		Each widget should implement the function.
		It responds to the mouse event sent by the ConsoleHandler
		(only for press down)
	*/
	virtual void actOnMouseEvent(MOUSE_EVENT_RECORD ) = 0;


	//Destructor
	virtual ~Widget() = 0;

};
