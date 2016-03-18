#pragma once
#include <Windows.h>
#include "Keys.h"

class ConsoleHandler;
/*
	An abstract class that has the basic functionality of a Widget.
	methods to be implemented in each separate widget:
		actOnKeyEvent(KEY_EVENT_RECORD) - how will the widget respond to each key event
		actOnMouseEvent(MOUSE_EVENT_RECORD) - how will the widget respond to each mouse event
*/
class Widget
{
protected:

	//Starting coordinate for the Widget
	COORD startPos;

	//The dimensions
	short width, height;

	//End coordinate for the Widget
	COORD endPos;

	//The key event that is sent from ConsoleHandler
	KEY_EVENT_RECORD key_input;

	//The mouse event that is sent from ConsoleHandler
	MOUSE_EVENT_RECORD mouse_input;

	/*A function that checks if the position of the console cursor
	is in the boundaries of the textBox
	*/
	bool isPositionLegal(COORD);

	//A method that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);


public:

	//Default widget Constructor parameters
	Widget() : startPos{ 0,0 }, endPos({ width,height}), width(20), height(10) {}

	//Constructor with parameters
	Widget(COORD start, short _width, short _height) : startPos(start), width(_width), height(_height),
		endPos({ startPos.X + _width,startPos.Y + _height-1 }) {}

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

	//Sets the key event
	virtual void setKeyEvent(KEY_EVENT_RECORD key)  { key_input = key; }

	/*
		Acts on key event
		Each widget should implement the function.
		It responds to the key event sent by the ConsoleHandler
		(only for press down)
	*/
	virtual void actOnKeyEvent(KEY_EVENT_RECORD) = 0;

	
	virtual MOUSE_EVENT_RECORD getMouseEvent() const { return mouse_input; }

	//Sets the mouse event
	virtual void setMouseEvent(MOUSE_EVENT_RECORD mouse) { mouse_input = mouse; }

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
