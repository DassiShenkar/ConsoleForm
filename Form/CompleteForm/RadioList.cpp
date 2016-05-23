#include "RadioList.h"
#include <iostream>
#include <string>
#include "Keys.h"
using namespace std;

//A default constructor that activates Widget default constructor
RadioList::RadioList() : Widget(), checked(0)
{
	item_list = new vector<string>;
}

//A constructor that recieves the starting coordinate and the list of items
RadioList::RadioList(COORD start, vector<string>* items) : Widget(start, 20, items->size() + 4),
item_list(items), checked(0)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Cursor's info
	CONSOLE_CURSOR_INFO ConsoleInfo = { 1,FALSE };
	SetConsoleCursorInfo(hout, &ConsoleInfo);



	printWidget();
}

//A method that responds only to up and down arrows from the keybord
void RadioList::actOnKeyEvent(KEY_EVENT_RECORD key)
{

	//On key pressed
	if (key.bKeyDown)
	{
		Keys type_of_key = determineTypeOfKey(key);
		switch (type_of_key)
		{
		case DOWN:		//Down arrow
			checked += 1;
			if (checked == item_list->size() + 1)
				checked = 1;
			printWidget();
			break;
		case UP:		//Down arrow
			checked -= 1;
			if (checked <= 0)
				checked = item_list->size();
			printWidget();
			break;
		default:
			break;
		}
	}
}

//A method that responds to mouse events
void RadioList::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Iterates through the item list
	for (int i = 0; i < item_list->size(); i++)
	{
		if (mouse.dwButtonState == 0x0001 &&					//If left click was pressed
			mouse.dwMousePosition.X == startPos.X + 1 &&
			mouse.dwMousePosition.Y == startPos.Y + i + 1)
		{
			checked = i + 1;			//Holds the number of item that was chosen
			printWidget();		//Reprints the list
		}
	}



}


//Prints the Radio List
void RadioList::printWidget() const
{

	//Gets the output handle
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Gets the console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save the original colors of the console
	WORD originalColors = ConsoleInfo->wAttributes;

	//Sets cursor to start position
	SetConsoleCursorPosition(hout, startPos);

	//Prints the upper boundary
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}

	//Iterates through the item list and prints the items
	for (short i = 0; i < item_list->size(); i++)
	{
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + i + 1 });
		if (checked == i + 1)
		{
			//If item was chosen then mark as X and set background to white and font to black

			cout << "|";
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			cout << "X " << i + 1 << " " << item_list->at(i);
			SetConsoleTextAttribute(hout, originalColors);
		}
		else
		{
			cout << "|O " << i + 1 << " " << item_list->at(i);
		}
		SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1, startPos.Y + i + 1 });
		cout << '|';

	}
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + short(item_list->size()) + 1 });

	//Prints the lower boundary
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}
}