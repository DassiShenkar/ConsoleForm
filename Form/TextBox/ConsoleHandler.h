#include "TextBox.h"
#include "Widget.h"
#include <Windows.h>
#include <iostream>

#include "LinkedList.h"


using namespace std;

/*
The ConsoleHandler class holds the Widgets and handles
the input and output commands.
*/

class ConsoleHandler
{
private:

	LinkedList<Widget> widgets;



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

};


/*
The Constructor initializes a textbox at COORD(10,10) and dimentions of width (20) and height (10)

*/
ConsoleHandler::ConsoleHandler()
{
	widgets.addItem(*(new TextBox({ 10,10 }, 20, 10)));
	//Print the textBox
	widgets[0].PrintWidget(widgets[0].getStartPosition());

	//Handle input
	getInputRecord();
}


//The main function that handles the input records
void ConsoleHandler::getInputRecord()
{
	HANDLE hStdin;						//standard input variable					
	DWORD fdwSaveOldMode;				//Will hold old mode to be restored before exit
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD inputRecord[128];		//The size of the buffer to read


										// Get the standard input handle.
	hStdin = GetStdHandle(STD_INPUT_HANDLE);


	//Handles error
	if (hStdin == INVALID_HANDLE_VALUE)
		//ErrorExit("GetStdHandle");
		exit(1);


	// Save the current input mode, to be restored on exit.
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		//ErrorExit("GetConsoleMode");
		exit(1);

	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		//ErrorExit("SetConsoleMode");
		exit(1);

	while (true)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			inputRecord,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
						//ErrorExit("ReadConsoleInput");
			exit(1);
		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (inputRecord[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(inputRecord[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(inputRecord[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
										   //ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				//ErrorExit("Unknown event type");
				break;
			}

		}
		//SetConsoleMode(hStdin, fdwSaveOldMode);

	}
}

//The function that responds to keyboard events
void ConsoleHandler::KeyEventProc(KEY_EVENT_RECORD key)
{

	widgets[0].actOnKeyEvent(key);
}


void ConsoleHandler::MouseEventProc(MOUSE_EVENT_RECORD mouse)
{
	widgets[0].actOnMouseEvent(mouse);
}