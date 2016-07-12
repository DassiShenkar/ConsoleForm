#pragma once
#include <Windows.h>
#include <vector>
#include "Enums.h"
#include "Graphics.h"



class Control
{
private:
	//The global control in focus
	static Control* globalControlInFocus;
protected:



	//The starting coordinates
	int startX, startY;

	//The dimensions
	int width, height;

	//The cursor coordinates
	int cursorX, cursorY;

	int layer;

	//The visibility of the widget
	bool isVisible;

	//Is the Control focusable
	bool focusable;

	//Indicates the foreground color of the wodget
	ForegroundColor foreground;

	//Indicates the background color of the wodget
	BackgroundColor background;

	//Indicates the type of border of the widget
	BorderType border;

	//A method that determines what type of key was pressed
	Keys determineTypeOfKey(KEY_EVENT_RECORD);

	//Auxiliary method to convert int to string
	string convertToString(int num);

public:

	//Constructor with parameters
	Control(int _height, int _width) : startX(0), startY(0), width(_width), height(_height),
		cursorX(0), cursorY(0), focusable(true), isVisible(true), border(BorderType::Single), layer(0) {}

	//Shows the control
	void Show();

	//Hides the Control
	void Hide();

	//Can the control get focus 
	bool canGetFocus() { return focusable; };




	/******************************************************************************/
	/*                            Getters/Setters								  */
	/******************************************************************************/

	//Gets all the controls
	void getAllControls(vector<Control*> controls) { controls.push_back(this); };

	void setFocusable(bool f) { focusable = f; }

	//Gets the global control in focus
	static Control* getGlobalInFocus() { return globalControlInFocus; }

	//Sets the global control in focus
	static void setGlobalFocus(Control *control) { globalControlInFocus = control; }

	//Sets the layer
	virtual void setLayer(int l) { layer = l; }

	//Gets the layer
	virtual int getLayer() const { return layer; }

	//Sets the Foreground color
	void setForeground(ForegroundColor color) { foreground = color; }

	//Sets the Background color
	void setBackground(BackgroundColor color) { background = color; }

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



	//Responds to key events
	virtual void keyDown(KEY_EVENT_RECORD) = 0;

	//Responds to left Click
	virtual void mousePressed(int x, int y, bool isLeft) = 0;

	virtual void draw(Graphics &g, int left, int top, int layer) = 0;

	//Prints the Border
	void printBorder(Graphics &g, int left, int top, int layer);


	//Destructor
	virtual ~Control() = 0;

};

