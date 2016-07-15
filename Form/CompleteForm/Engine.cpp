#include "EventEngine.h"

EventEngine::EventEngine() : _graphics(*Graphics::getInstance())
{

}

void EventEngine::run(Control& Control)
{
	HANDLE _console;						//standard input variable					
	DWORD fdwSaveOldMode;				//Will hold old mode to be restored before exit
	DWORD count, fdwMode, i;
	INPUT_RECORD record;		//The size of the buffer to read	for (;;) 	{		_graphics.clearScreen();		_graphics.setCursorVisibility(false);		Control.printWidget(); //(_graphics, 0, 0);		ReadConsoleInput(_console, &record, 1, &count);				if (record.EventType == KEY_EVENT && /*Widget::getFocus() != nullptr*/ record.Event.KeyEvent.bKeyDown)			Control.keyDown(record.Event.KeyEvent);		if (record.EventType == MOUSE_EVENT)			Control.mousePressed(record.Event.Mouse);			}
}