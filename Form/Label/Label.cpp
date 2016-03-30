#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;

//A default constructor that activates the default Widget constructor
Label::Label() : Widget(), text("hello world")
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	

	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(s, &cursor_info);

	WORD originalColors = ConsoleInfo->wAttributes;

	SetConsoleCursorPosition(s, startPos);
	SetConsoleTextAttribute(s, FOREGROUND_RED);
	CONSOLE_CURSOR_INFO console;
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);

	printf("%s", text);

	SetConsoleTextAttribute(s, originalColors);



}

//A constructor that recieves the starting coordinate
Label::Label(COORD start, string _text) : Widget(start, _text.length() + 4, 3), text(_text)
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(s, &cursor_info);

	WORD originalColors = ConsoleInfo->wAttributes;

	CONSOLE_CURSOR_INFO console;
	PrintWidget(startPos);
	COORD center = { startPos.X + ((getWidth() - 1 - (text.length() - 1)) / 2),startPos.Y + 1 };
	SetConsoleCursorPosition(s, center);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	cout << text;
	SetConsoleTextAttribute(s, originalColors);



}


//The label does not respond to any key event
void Label::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

//The label does not respond to any mouse event
void Label::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	;
}



