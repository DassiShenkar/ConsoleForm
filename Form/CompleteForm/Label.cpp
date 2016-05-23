#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;

//A default constructor that activates the default Widget constructor
Label::Label() : Widget(), text("hello world")
{
	printWidget();
}

Label::Label(int _width): Widget({0,0},_width,1)
{
	printWidget();
}

//A constructor that recieves the starting coordinate
Label::Label(COORD start, string _text) : Widget(start, _text.length() + 4, 3), text(_text)
{
	printWidget();
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


void Label::setText(string _text)
{
	COORD tmp = this->getStartPosition();
	this->~Label();
	new (this) Label(tmp, _text);
}

void Label::printWidget() const
{
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(s, &cursor_info);

	WORD originalColors = ConsoleInfo->wAttributes;
	CONSOLE_CURSOR_INFO console;
	
	COORD center = startPos;
	char frame_top = ' ';
	char frame_side = ' ';
	switch (border)
	{
	case BorderType::None:
		center = { startPos.X + (short)((getWidth()  - (text.length() - 1)) / 2),startPos.Y + 1 };
		break;
	case BorderType::Single:
		center = { startPos.X + (short)((getWidth() - 1 - (text.length() - 1)) / 2),startPos.Y + 1 };
		frame_top = '-';
		frame_side = '|';
		break;
	case BorderType::Double:
		center = { startPos.X + (short)((getWidth() - 2 - (text.length() - 1)) / 2),startPos.Y + 1 };
		frame_top = '\xcd';
		frame_side = '\xba';
		break;
	default:
		break;
	}
	
	printBorder();
	SetConsoleCursorPosition(s, center);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	cout << text;
	SetConsoleTextAttribute(s, originalColors);

}


