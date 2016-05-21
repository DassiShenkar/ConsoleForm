
#include "Widget.h"

#include <Windows.h>
#include <iostream>
#include <vector>





using namespace std;

/*
The ConsoleHandler class holds the Widgets and Delivers
the input commands to the widgets.
*/

class ConsoleHandler
{
private:

	//The linked list will hold the widgets
	vector<Widget*> widgets;
	static ConsoleHandler* _instance;
	ConsoleHandler() : widgets(*new vector<Widget*>()) {}

	ConsoleHandler(ConsoleHandler&);
	ConsoleHandler& operator=(const ConsoleHandler&);

	//The function that responds to keyboard events
	void notifyWidgetsOnKey(KEY_EVENT_RECORD);

	//The function that responds to the mouse events
	void notifyWidgetsOnMouse(MOUSE_EVENT_RECORD);

	//The main function that handles the input records
	void getInputRecord();


public:
	
	vector<Widget*> getWidgetList() const { return widgets; }
	
	static ConsoleHandler* getInstance()
	{
		if (!_instance)
			_instance = new ConsoleHandler();
		return _instance;
	}

	//Adds the widget to the list of widgets
	void attach(Widget * widget) { widgets.push_back(widget); }

	

	


};


