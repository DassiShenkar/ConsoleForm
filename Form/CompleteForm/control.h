#pragma once
#include <Windows.h>
#include <vector>
#include "Keys.h"
#include "Graphics.h"


/*
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BorderType { Single, Double, None };*/

/*
An abstract class that has the basic functionality of a Widget.
methods to be implemented in each separate widget:
actOnKeyEvent(KEY_EVENT_RECORD) - how will the widget respond to each key event
actOnMouseEvent(MOUSE_EVENT_RECORD) - how will the widget respond to each mouse event
*/
//class Graphics;
class Control
{
private:
	static Control* focused;
protected:

	bool focusable;

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

	string convertToString(int num);

public:

	//Default widget Constructor parameters
	Control() : startPos{ 0,0 }, endPos({ width,height }), width(20),
		height(10), isVisible(true), border(BorderType::Single), focusable(true) {}

	//Constructor with parameters
	Control(int _height, int _width) : startPos({ 0,0 }), width(_width), height(_height),
		endPos({ startPos.X + (short)_width,startPos.Y + (short)_height - 1 }),
		focusable(true),isVisible(true), border(BorderType::Single) {}


	//Returns the width 
	virtual int getWidth() const { return width; }

	//Returns the height
	virtual int getHeight() const { return height; }

	//Sets the width
	virtual void setWidth(int _width) { width = _width; }

	//Sets the height
	virtual void setHeight(int _height) { height = _height; }

	//Sets the starting coordinate
	virtual void setStartPosition(COORD start) { startPos = start; endPos = { startPos.X + width, startPos.Y + height }; }

	//Returns the starting coordinate
	virtual COORD getStartPosition() const { return startPos; }

	//Returns the end coordinate
	virtual COORD getEndPosition() const { return endPos; }

	//Sets the end coordinate
	virtual void setEndPosition(COORD end) { endPos = end; }



	void Show();

	void Hide();

	//Sets the Foreground color
	void setForeground(ForegroundColor color);

	//Sets the Background color
	void setBackground(BackgroundColor color);

	//Sets the border type
	void setBorder(BorderType border);

	static Control* getFocused() { return focused; }	static void setFocus(Control *control) { focused = control; };
	bool canGetFocus() { return focusable; };
	void getAllControls(vector<Control*>* controls) { controls->push_back(this); };


	/*
	Acts on key event
	Each widget should implement the function.
	It responds to the key event sent by the ConsoleHandler
	(only for press down)
	*/
	virtual void keyDown(KEY_EVENT_RECORD) = 0;



	/*
	Acts on mouse event
	Each widget should implement the function.
	It responds to the mouse event sent by the ConsoleHandler
	(only for press down)
	*/
	virtual void mousePressed(int x, int y) = 0;

	//Prints the widget to the screen
	virtual void printWidget() = 0;

	virtual void draw(Graphics &g, int left, int top, int layer)=0;

	//Prints the Border
	void printBorder(Graphics &g, int left, int top, int layer);


	//Destructor
	virtual ~Control() = 0;

};
