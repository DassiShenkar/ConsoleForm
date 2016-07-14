#pragma once
#include <Windows.h>
#include <vector>
#include "Enums.h"
#include "Graphics.h"


/*******************************************************************************
*An Abstract class that implements a control.								   *
*draw, keyDown, mousePressed should be implemented							   *
*******************************************************************************/
class Control
{
private:
	//The global control in focus
	static Control* controlInFocus;
protected:



	//The starting coordinates
	int startX, startY;

	//The dimensions
	int width, height;

	//The cursor coordinates
	int cursorX, cursorY;

	//The layer of the control
	int layer;

	//If cursor should be shown on screen
	bool showCursor;

	//The visibility of the widget
	bool isVisible;

	//Is the Control focusable
	bool focusable;

	//Indicates the foreground color of the wodget
	Color foreground;

	//Indicates the background color of the wodget
	Color background;

	//Indicates the type of border of the widget
	BorderType border;

	//A method that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);

	//Auxiliary method to convert int to string
	string convertToString(int num);

public:

	//Constructor with parameters
	Control(int _height, int _width) : startX(0), startY(0), width(_width), height(_height),foreground(Color::White),
		cursorX(0), cursorY(0), focusable(true), isVisible(true), border(BorderType::Single), layer(0), showCursor(false) {}

	//Shows the control
	void Show();

	//Hides the Control
	void Hide();

	//Can the control get focus 
	bool canGetFocus() { return focusable; };

	//Prints the Border
	void printBorder(Graphics &g, int left, int top, int layer);


	/******************************************************************************/
	/*                            Abstract functions								  */
	/******************************************************************************/


	//Responds to key events
	virtual void keyDown(KEY_EVENT_RECORD) = 0;

	//Responds to left Click
	virtual void mousePressed(int x, int y, bool isLeft) = 0;

	virtual void draw(Graphics &g, int left, int top, int layer) = 0;



	/******************************************************************************/
	/*                            Getters/Setters								  */
	/******************************************************************************/

	//Gets all the controls
	virtual void getAllControls(vector<Control*>& controls) { controls.push_back(this); };

	void setFocusable(bool f) { focusable = f; }

	//Gets the global control in focus
	static Control* getFocused() { return controlInFocus; }


	//Sets the global control in focus
	static void setFocus(Control *control);
	
	//Sets the layer
	virtual void setLayer(int l) { layer = l; }

	//Sets the bool value of showCursor
	virtual void cursorVisibility(bool b) { showCursor = b; }

	//Gets the bool value of showCursor
	virtual bool getCursorVisibility() const { return showCursor; }

	//Gets the layer
	virtual int getLayer() const { return layer; }

	//Sets the Foreground color
	void setForeground(Color color) { foreground = color; }

	//Sets the Background color
	void setBackground(Color color) { background = color; }

	//Sets the border type
	void setBorder(BorderType _border) { border = _border; }

	//Returns the width 
	virtual int getWidth() const { return width; }

	//Returns the height
	virtual int getHeight() const { return height; }

	//Sets the width
	virtual void setWidth(int _width) { width = _width; }

	//Sets the height
	virtual void setHeight(int _height) { height = _height; }

	//Sets the starting coordinate
	virtual void setStartPosition(int x, int y) { startX = x; startY = y; }

	//Returns the starting x coordinate
	virtual int getStartX() const { return startX; }

	//Returns the starting x coordinate
	virtual void setStartX(int x) { startX = x; }

	//Returns the starting y coordinate
	virtual int getStartY() const { return startY; }

	//Returns the starting y coordinate
	virtual void setStartY(int y) { startY = y; }

	//Returns the cursor x coordinate
	virtual int getCursorX() const { return cursorX; }

	//Returns the cursor x coordinate
	virtual void setCursorX(int x) { cursorX = x; }

	//Returns the cursor y coordinate
	virtual int getCursorY() const { return cursorY; }

	//Returns the cursor x coordinate
	virtual void setCursorY(int y) { cursorY = y; }


	//Sets the cursor position
	virtual void setCursorPosition(int x, int y) { cursorX = x; cursorY = y; }

	//Destructor
	virtual ~Control() = 0;

};

