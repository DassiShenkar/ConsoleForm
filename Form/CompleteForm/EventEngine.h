#pragma once

#include "Control.h"
#include <Windows.h>
#include "Graphics.h"
/*******************************************************************************
*A Class that implements an Engine. It's job is to interact with mouse/keyboard*
*and move the commands to the aprropriate control.
*******************************************************************************/
class EventEngine
{
public:
	//Constructor
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control &c);
	virtual ~EventEngine();
private:
	void moveFocus(Control &main, Control *focused);

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};