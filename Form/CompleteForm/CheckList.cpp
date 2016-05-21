#include "CheckList.h"
#include <iostream>
#include <string>
using namespace std;

//Default Constructor that activates the Widget default construcotr
CheckList::CheckList() : Widget()
{

	//Initializes a new list to hold the items
	item_list = new vector<string>;
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(hout, &cursor_info);
}

//Constructor that recieves as parameters the starting coordinate and the items in a list 
CheckList::CheckList(COORD start, vector<string>* items) : Widget(start, 20, items->size() + 4),
item_list(items)
{
	checked = new bool[items->size()];

	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(hout, &cursor_info);

	//Initializes the checked array to false
	for (int i = 0; i < items->size(); i++)
	{
		checked[i] = false;
	}


	printCheckList();
}


//The Check list does not respond to key events
void CheckList::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	//Gets the handle for the output
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Gets the console's info  
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Saves the original colors of the console
	WORD originalColors = ConsoleInfo->wAttributes;

	//Save the current cursor position
	COORD cursor_pos = ConsoleInfo->dwCursorPosition;

	COORD temp;


	//If key is pressed
	if (key.bKeyDown)
	{
		Keys type_of_key = determineTypeOfKey(key);
		switch (type_of_key)
		{
		case DOWN:			//Down arrow 
			if (cursor_pos.Y + 1 > short(startPos.Y + item_list->size()))
				SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + 1 });

			else
				SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y + 1 });

			GetConsoleScreenBufferInfo(hout, ConsoleInfo);
			temp = ConsoleInfo->dwCursorPosition;
			printCheckList();
			SetConsoleCursorPosition(hout, temp);

			break;
		case UP:				//Up arrow
			if (cursor_pos.Y - 1 < startPos.Y + 1)
				SetConsoleCursorPosition(hout, { startPos.X + 1, short(startPos.Y + item_list->size()) });

			else
				SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y - 1 });
			GetConsoleScreenBufferInfo(hout, ConsoleInfo);
			temp = ConsoleInfo->dwCursorPosition;
			printCheckList();
			SetConsoleCursorPosition(hout, temp);

			break;

		case ENTER:				//Enter key

			for (int i = 0; i < item_list->size(); i++)
			{
				if (cursor_pos.Y - startPos.Y == i + 1)
				{
					checked[i] = !checked[i];
					printCheckList();
				}
				SetConsoleCursorPosition(hout, cursor_pos);
			}

		default:
			break;
		}
	}

}


//A method that responds to a mouse event 
void CheckList::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Updates the checked array based on the location of the mouse click and reprints the list
	for (int i = 0; i < item_list->size(); i++)
	{
		if (mouse.dwButtonState == 0x0001 &&				//If left click is pressed
			mouse.dwMousePosition.X == startPos.X + 1 &&
			mouse.dwMousePosition.Y == startPos.Y + i + 1)
		{
			checked[i] = !checked[i];			//Reverses state on each click
			printCheckList();
		}
	}



}

//Prints the check list
void CheckList::printCheckList() const
{
	//Gets the output handle
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Gets the Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	COORD current_pos = ConsoleInfo->dwCursorPosition;

	//Saves the original colors of the screen
	WORD originalColors = ConsoleInfo->wAttributes;

	//Sets the position to the start
	SetConsoleCursorPosition(hout, startPos);
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';		//Upper Boundary
	}

	short cursor_pos = current_pos.Y - startPos.Y;
	//Iterates through the items
	for (short i = 0; i < item_list->size(); i++)
	{
		//Set the cursor to the next line
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + i + 1 });

		//If the current item is checked
		if (checked[i] == true)
		{
			//White background and black font

			cout << "|";
			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			cout << "X " << i + 1 << " " << item_list->at(i);

			//Restore original colors
			SetConsoleTextAttribute(hout, originalColors);
		}

		//Else if item is not picked
		else
		{
			cout << "|";
			if (i + 1 == cursor_pos)
				SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			cout << "O " << i + 1 << " " << item_list->at(i);
			SetConsoleTextAttribute(hout, originalColors);
		}

		//Set the cursor to the end of the line
		SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1, startPos.Y + i + 1 });
		cout << '|';

	}

	//Set the cursor to the end and pprint the bottom boundary
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + short(item_list->size()) + 1 });
	for (int i = 0; i < getWidth(); i++)
	{
		cout << '-';
	}
}