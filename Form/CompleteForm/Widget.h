#pragma once
#include <Windows.h>
#include "Keys.h"



enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BorderType { Single, Double, None };

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

	

	//The visibility of the widget
	bool isVisible;

	//Indicates the foreground color of the wodget
	ForegroundColor foreground;

	//Indicates the background color of the wodget
	BackgroundColor background;

	//Indicates the type of border of the widget
	BorderType border;

	//A method that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);

	//Prints the wigdet to the screen
	virtual void printWidget() const = 0;

	void printBorder() const;


public:

	//Default widget Constructor parameters
	Widget() : startPos{ 0,0 }, endPos({ width,height }), width(20), height(10), isVisible(true), border(BorderType::Single) {}

	//Constructor with parameters
	Widget(COORD start, short _width, short _height) : startPos(start), width(_width), height(_height),
		endPos({ startPos.X + _width,startPos.Y + _height - 1 }) , isVisible(true), border(BorderType::Single) {}


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

	//Sets the visibility of the widget
	void setVisibility(bool visibility);

	//Sets the Foreground color
	void setForeground(ForegroundColor color);

	//Sets the Background color
	void setBackground(BackgroundColor color);

	//Sets the border type
	void setBorder(BorderType border);

	

	/*
	Acts on key event
	Each widget should implement the function.
	It responds to the key event sent by the ConsoleHandler
	(only for press down)
	*/
	virtual void actOnKeyEvent(KEY_EVENT_RECORD) = 0;



	/*
	Acts on mouse event
	Each widget should implement the function.
	It responds to the mouse event sent by the ConsoleHandler
	(only for press down)
	*/
	virtual void actOnMouseEvent(MOUSE_EVENT_RECORD) = 0;


	//Destructor
	virtual ~Widget() = 0;

};
