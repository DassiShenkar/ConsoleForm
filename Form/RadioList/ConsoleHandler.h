#include "Widget.h"
#include <Windows.h>
#include <iostream>
#include "LinkedList.h"
#include "RadioList.h"


using namespace std;

/*
The ConsoleHandler class holds the Widgets and Delivers
the input commands to the widgets.
*/

class ConsoleHandler
{
private:

	//The linked list will hold the widgets
	LinkedList<Widget*> widgets;

public:
	//Constructor - Already contains a textBox
	ConsoleHandler();

	//-------------------------------Maybe add constructor that recieves widgets as parameters -----------

	//The main function that handles the input records
	void getInputRecord();

	//The function that responds to keyboard events
	void KeyEventProc(KEY_EVENT_RECORD);

	//The function that responds to the mouse events
	void MouseEventProc(MOUSE_EVENT_RECORD);

	LinkedList<Widget*> getWidgetList() const { return widgets; }

};


