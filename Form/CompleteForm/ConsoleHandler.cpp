#include "ConsoleHandler.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;




ConsoleHandler* ConsoleHandler::_instance = 0;

ConsoleHandler::ConsoleHandler() : widgets(*new vector<Widget*>()) 
{
	
}

void ConsoleHandler::start() 
{
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
				notifyWidgetsOnKey(inputRecord[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				notifyWidgetsOnMouse(inputRecord[i].Event.MouseEvent);
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
void ConsoleHandler::notifyWidgetsOnKey(KEY_EVENT_RECORD key)
{
	for (int i = 0; i < widgets.size(); i++)
	{
		widgets.at(i)->actOnKeyEvent(key);
	}

}

//The function that responds to mouse events
void ConsoleHandler::notifyWidgetsOnMouse(MOUSE_EVENT_RECORD mouse)
{
	for (int i = 0; i < widgets.size(); i++)
	{
		widgets.at(i)->actOnMouseEvent(mouse);
	}
}