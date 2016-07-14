#include "RadioList.h"
#include <iostream>
#include <string>
#include "Keys.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
RadioList::RadioList(int _width, int _height, vector<string> items) : Widget(_width, _height),
item_list(items), checked(0)
{
	
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
			if (checked == item_list.size() + 1)
				checked = 1;
			printWidget();
			break;
		case UP:		//Down arrow
			checked -= 1;
			if (checked <= 0)
				checked = item_list.size();
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
	for (size_t i = 0; i < item_list.size(); i++)
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

	printBorder();
	//Iterates through the item list and prints the items
	short i = 0;
	for (vector<string>::const_iterator it=item_list.begin(); it!= item_list.end(); it++,i++)
	{

		SetConsoleCursorPosition(hout, { startPos.X+1, startPos.Y + i + 1 });
		if (checked == i + 1)
		{
			//If item was chosen then mark as X and set background to white and font to black
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			cout << "X " << i + 1 << " " << *it;
			SetConsoleTextAttribute(hout, originalColors);
		}
		else
		{
			cout << "O " << i + 1 << " " << *it;
		}

	}
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + short(item_list.size()) + 1 });
}