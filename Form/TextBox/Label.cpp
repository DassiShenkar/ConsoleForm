#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;


Label::Label() : Widget(), text("hello world")
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;
	
	SetConsoleCursorPosition(s, startPos);
	SetConsoleTextAttribute(s, FOREGROUND_RED);
	CONSOLE_CURSOR_INFO console;
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);

	printf("%s", text);

	SetConsoleTextAttribute(s, originalColors);



}

Label::Label(COORD start, string _text) : Widget(start, _text.length() + 4, 3), text(_text)
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
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

Label::Label(COORD start, short _width, short _height, string _text) : Widget(start,_width,_height), text(_text)
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;
	
	CONSOLE_CURSOR_INFO console;
	PrintWidget(startPos);
	COORD center = { startPos.X+((getWidth() - 2- (text.length()-1)) / 2),startPos.Y+((getHeight() - 2) / 2) };
	SetConsoleCursorPosition(s, center);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	cout << text;
	SetConsoleTextAttribute(s, originalColors);

}

void Label::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}
void Label::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	;
}



