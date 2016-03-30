#include "ComboBox.h"
#include <iostream>
#include <string>
using namespace std;

//A default constructor that activates the Widget default constructor
ComboBox::ComboBox() : Widget(), header("Select Item"), drop_down(false) 
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(hout, &cursor_info);
}

//A constructor that gets the starting coordinate of the Combo Box and the list of items
ComboBox::ComboBox(COORD start, LinkedList<string&>* items) : Widget(start, 20, items->getCount() + 4),
item_list(*items), header("Select Item"), drop_down(false)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//Cursor's info
	CONSOLE_CURSOR_INFO cursor_info = { 1,FALSE };
	SetConsoleCursorInfo(hout, &cursor_info);
	printComboBox();
}

//The combo box does not respond to key events
void ComboBox::actOnKeyEvent(KEY_EVENT_RECORD key)
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

							//If the drop down menu is closed then open it print the menu and set cursor to first item
			if (drop_down == false)
			{
				drop_down = true;
				
				SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + 3 });
				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				temp = ConsoleInfo->dwCursorPosition;
				printComboBox();
				SetConsoleCursorPosition(hout, temp);
			}
			
				
			//Else, move down the items
			else
			{

				//If reaches the last item then go back to the first
				if (cursor_pos.Y-startPos.Y == (item_list.getCount() + 2))
					SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + 3 });
				else
					SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y + 1 });

				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				temp = ConsoleInfo->dwCursorPosition;
				printComboBox();
				SetConsoleCursorPosition(hout, temp);
				
			}
			break;
		case UP:				//Up arrow

								//If the drop down menu is closed then open it print the menu and set cursor to last item
			if (drop_down == false)
			{
				drop_down = true;
				SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + short(item_list.getCount() + 2) });
				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				temp = ConsoleInfo->dwCursorPosition;
				printComboBox();
				SetConsoleCursorPosition(hout, temp);
			}

			//Else, iterate up through the items
			else
			{

				//If reaches the first item then go to the last item
				if (cursor_pos.Y == (startPos.Y + 3))
					SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + short(item_list.getCount() + 2) });
				else
					SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y - 1 });
				
				
				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				temp = ConsoleInfo->dwCursorPosition;
				printComboBox();
				SetConsoleCursorPosition(hout, temp);
			}
			break;

		case ENTER:				//Enter key

								//If drop down menu is open
			if (drop_down == true)
			{
				drop_down = false;
				for (short i = 0; i < item_list.getCount(); i++)
				{
					if (cursor_pos.Y == startPos.Y + i + 3)
					{
						setHeader(item_list[i].getData());
						printComboBox();

						SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + 1 });
					}
				}
			}
		default:
			break;
		}
	}
}

//A ,ethod that respond to key events
void ComboBox::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;


	if (mouse.dwButtonState == 0x0001 &&						//If left click is pressed
		mouse.dwMousePosition.X == startPos.X + 1 &&
		mouse.dwMousePosition.Y == startPos.Y + 1)
	{

		//If drop down menu is closed then open it
		if (drop_down == false)
		{
			drop_down = true;
			printComboBox();
		}

		//Else, close the menu
		else
		{
			drop_down = false;
			printComboBox();
		}

	}

	//Else if right click is pressed on the number on the left side
	else if (mouse.dwButtonState == 0x0001 &&
		mouse.dwMousePosition.X == startPos.X + 1)

	{
		for (int i = 0; i < item_list.getCount(); i++)
		{

			//If the drop down menu is closed then do nothing
			if (drop_down == false)
			{

				;

			}

			//Else if the drop menu is open and the click is on the given line 
			else
			{
				if (mouse.dwMousePosition.Y == startPos.Y + i + 3)
				{
					//Set the header to the given item
					this->setHeader(item_list[i].getData());

					//Clears the header before updating
					clearLabel();

					//Closes the menu and reprints the combo box
					drop_down = false;
					printComboBox();
				}
			}
		}
	}
}

//Prints the Combo box
void ComboBox::printComboBox()
{
	//Gets the handle for the output
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Gets the console's info  
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	COORD current_pos = ConsoleInfo->dwCursorPosition;

	//Saves the original colors of the console
	WORD originalColors = ConsoleInfo->wAttributes;

	//Set cursor to start position
	SetConsoleCursorPosition(hout, startPos);


	//Prints the upper boundary of the header
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}


	//Outputs to the screen:   |O "header" | and sets background to white and font to black 
	SetConsoleCursorPosition(hout, { startPos.X,startPos.Y + 1 });
	cout << '|';
	SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << "O| " << header;
	SetConsoleTextAttribute(hout, originalColors);
	SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1,startPos.Y + 1 });
	cout << '|';
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + 2 });

	//Prints the lower boundary of the label
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}

	//If the drop down menu should be open
	if (drop_down == true)
	{
		//Prints the body
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + 3 });
		int body_height = item_list.getCount();
		GetConsoleScreenBufferInfo(hout, ConsoleInfo);
		short cursor_pos = current_pos.Y-startPos.Y;
		for (short i = 0; i < body_height; i++)
		{
			
			cout << "|";
			if (i + 3 == cursor_pos)
				SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); 
			cout<< i + 1 << "| " << item_list[i].getData();
			SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1,startPos.Y + i + 3 });
			SetConsoleTextAttribute(hout, originalColors);
			cout << '|';
			SetConsoleCursorPosition(hout, { startPos.X ,startPos.Y + i + 4 });
			
		}

		//Prints the lower boundary
		for (int i = 0; i < width; i++)
		{
			cout << "-";
		}
	}

	//Else if the body should be hidden then clear it
	else
	{
		clearBody();
	}

}

//Clears the header label
void ComboBox::clearLabel()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;

	SetConsoleCursorPosition(hout, { startPos.X,startPos.Y + 1 });
	for (int i = 0; i < width; i++)
	{
		cout << " ";
	}


}

//Clears the body 
void ComboBox::clearBody()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;

	//Clears the body
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + 3 });
	int body_height = item_list.getCount();

	for (short i = 0; i < body_height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << " ";
		}
		SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1,startPos.Y + i + 3 });
		cout << ' ';
		SetConsoleCursorPosition(hout, { startPos.X ,startPos.Y + i + 4 });
	}

	//Clear lower boundary
	for (int i = 0; i < width; i++)
	{
		cout << " ";
	}

}