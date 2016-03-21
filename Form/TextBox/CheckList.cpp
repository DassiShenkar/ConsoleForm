#include "CheckList.h"
#include <iostream>
#include <string>
using namespace std;

CheckList::CheckList() : Widget()
{
	checked = new bool[1];
	checked[0] = false;
	item_list = new LinkedList<string&>;
	
}

CheckList::CheckList(COORD start, LinkedList<string&>* items) : Widget(start, 20, items->getCount() + 4),
item_list(items)
{
	checked = new bool[items->getCount()];
	for (int i = 0; i < items->getCount(); i++)
	{
		checked[i] = false;
	}
	printCheckList();
}

void CheckList::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}

void CheckList::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
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
			checked[i] = !checked[i];
			printCheckList();
		}
	}



}

void CheckList::printCheckList() const
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
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + i + 1 });
		if (checked[i]==true)
		{
			cout << "|X " << i + 1 << " " << item_list->operator[](i).getData();
		}
		else
		{
			cout << "|O " << i + 1 << " " << item_list->operator[](i).getData();
		}
		SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1, startPos.Y + i + 1 });
		cout << '|';

	}
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + short(item_list->getCount()) + 1 });
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}
}