#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;


Label::Label(int _width): Widget(_width,3)
{
	
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
	text = _text;
	width = _text.length()+2;
	printWidget();
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
		break;
	case BorderType::Double:
		center = { startPos.X + (short)((getWidth() - 2 - (text.length() - 1)) / 2),startPos.Y + 1 };
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


