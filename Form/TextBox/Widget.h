#pragma once
#include <Windows.h>
#include "Keys.h"

class Widget
{
protected:
	COORD startPos;
	COORD endPos;
	short width, height;
	KEY_EVENT_RECORD key_input;
	MOUSE_EVENT_RECORD mouse_input;

	/*A function that checks if the position of the console cursor
	is in the boundaries of the textBox
	*/
	bool isPositionLegal(COORD);

	//A function that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);


public:
	Widget() : startPos{ 0,0 }, endPos({ short(width),short(height) }), width(20), height(10) {}
	Widget(COORD start, short _width, short _height) : startPos(start), width(_width), height(_height),
		endPos({ startPos.X + _width,startPos.Y + _height }) {}
	virtual void PrintWidget(COORD);
	virtual short getWidth() const { return width; }
	virtual short getHeight() const { return height; }
	virtual void setWidth(short _width) { width = _width; }
	virtual void setHeight(short _height) { height = _height; }
	virtual void setStartPosition(COORD start) { startPos = start; }
	virtual COORD getStartPosition() const { return startPos; }
	virtual COORD getEndPosition() const { return endPos; }
	virtual void setEndPosition(COORD end) { endPos = end; }
	virtual KEY_EVENT_RECORD getKeyEvent() const { return key_input; }
	virtual void setKeyEvent(KEY_EVENT_RECORD) = 0;
	virtual MOUSE_EVENT_RECORD getMouseEvent() const { return mouse_input; }
	virtual void setMouseEvent(MOUSE_EVENT_RECORD mir) { mouse_input = mir; }

	virtual ~Widget() = 0;

};
