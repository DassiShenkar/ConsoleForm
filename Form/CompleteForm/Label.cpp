#include "Label.h"
#include <iostream>
#include <string.h>
using namespace std;


Label2::Label2(int _width) : Control(1, _width)
{

}


//The label does not respond to any key event
void Label2::keyDown(KEY_EVENT_RECORD key)
{
	;
}

//The label does not respond to any mouse event
void Label2::mousePressed(int x, int y)
{
	;
}


void Label2::setText(string _text)
{
	text = _text;
	width = _text.length() + 2;
	//printWidget();
}

void Label2::printWidget()
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
		center = { startPos.X + (short)((getWidth() - (text.length() - 1)) / 2),startPos.Y + 1 };
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

	//	printBorder();
	SetConsoleCursorPosition(s, center);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	cout << text;
	SetConsoleTextAttribute(s, originalColors);

}

void Label2::draw(Graphics &g, int left, int top, int layer)
{

	COORD center = { left,top };
	string frame_top = " ";
	string frame_side = " ";
	switch (border)
	{
	case BorderType::None:
		center = { short(left) + (short)((getWidth() - (text.length() - 1)) / 2), short(top) + 1 };
		break;
	case BorderType::Single:
		center = { short(left) + (short)((getWidth() - 1 - (text.length() - 1)) / 2), short(top) + 1 };
		break;
	case BorderType::Double:
		center = { short(left) + (short)((getWidth() - 2 - (text.length() - 1)) / 2), short(top) + 1 };
		break;
	default:
		break;
	}

	printBorder(g, left, top, layer);
	g.moveTo(center.X, center.Y);
	//SetConsoleCursorPosition(s, center);
	g.setForeground(Color::Green);
	//SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	g.setCursorVisibility(false);
	//console.bVisible = FALSE;
	//SetConsoleCursorInfo(s, &console);
	g.write(text);
	//cout << text;
	g.setForeground(Color::White);
	//SetConsoleTextAttribute(s, originalColors);


}


