#include "RadioList.h"
#include <iostream>
#include <string>
using namespace std;

RadioList::RadioList() : Widget(), checked(0)
{
	item_list = new LinkedList<string&>;
}

RadioList::RadioList(COORD start, LinkedList<string&>* items) : Widget(start, 20, items->getCount() + 4), 
item_list(items), checked(0)
{
	printRadioList();
}

void RadioList::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

void RadioList::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;
	for (int i = 0; i < item_list->getCount(); i++)
	{
		if (mouse.dwButtonState == 0x0001 &&
			mouse.dwMousePosition.X == startPos.X + 1 &&
			mouse.dwMousePosition.Y == startPos.Y + i + 1)
		{
			checked = i+1;
			printRadioList();
		}
	}
	
			
	
}

void RadioList::printRadioList() const
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;

	SetConsoleCursorPosition(hout, startPos);
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}

	
	for (short i = 0; i < item_list->getCount(); i++)
	{
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + i + 1});
		if (checked == i + 1)
		{
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			cout << "|X " << i + 1 << " " << item_list->operator[](i).getData();
			SetConsoleTextAttribute(hout, originalColors);
		}
		else
		{
			cout << "|O " << i + 1 << " " << item_list->operator[](i).getData();
		}
		SetConsoleCursorPosition(hout, { startPos.X+getWidth()-1, startPos.Y + i + 1 });
		cout << '|';
		
	}
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + short(item_list->getCount()) + 1 });
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}
}