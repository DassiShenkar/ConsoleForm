#include "Label.h"
#include <iostream>


Label::Label() : x(0), y(0), text("hello world")
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(s, position);
	SetConsoleTextAttribute(s, FOREGROUND_RED);
	CONSOLE_CURSOR_INFO console;
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);

	printf("%s", text);

	SetConsoleTextAttribute(s, originalColors);



}
Label::Label(int _x, int _y, char * _text) : x(_x), y(_y), text(_text)
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;
	COORD position;
	CONSOLE_CURSOR_INFO console;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(s, position);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	printf("%s", text);
	SetConsoleTextAttribute(s, originalColors);

}
