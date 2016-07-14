#include "CheckList2.h"
#include <iostream>
#include <string>
using namespace std;



//Constructor that recieves as parameters the starting coordinate and the items in a list 
CheckList2::CheckList2(int _height, int _width, vector<string> items) : Control(_height+2, _width),
item_list(items)
{
	checked = new bool[items.size()];


	//Initializes the checked array to false
	for (size_t i = 0; i < items.size(); i++)
	{
		checked[i] = false;
	}

}


//The Check list does not respond to key events
void CheckList2::keyDown(KEY_EVENT_RECORD key)
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
			if (cursor_pos.Y + 1 > short(startPos.Y + item_list.size()))
				SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + 1 });

			else
				SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y + 1 });

			GetConsoleScreenBufferInfo(hout, ConsoleInfo);
			temp = ConsoleInfo->dwCursorPosition;
			printWidget();
			SetConsoleCursorPosition(hout, temp);

			break;
		case UP:				//Up arrow
			if (cursor_pos.Y - 1 < startPos.Y + 1)
				SetConsoleCursorPosition(hout, { startPos.X + 1, short(startPos.Y + item_list.size()) });

			else
				SetConsoleCursorPosition(hout, { startPos.X + 1, cursor_pos.Y - 1 });
			GetConsoleScreenBufferInfo(hout, ConsoleInfo);
			temp = ConsoleInfo->dwCursorPosition;
			printWidget();
			SetConsoleCursorPosition(hout, temp);

			break;

		case ENTER:				//Enter key

			for (size_t i = 0; i < item_list.size(); i++)
			{
				if (cursor_pos.Y - startPos.Y == i + 1)
				{
					checked[i] = !checked[i];
					printWidget();
				}
				SetConsoleCursorPosition(hout, cursor_pos);
			}

		default:
			break;
		}
	}

}


//A method that responds to a mouse event 
void CheckList2::mousePressed(int x, int y)
{
	Control::setFocus(this);
	

	//Updates the checked array based on the location of the mouse click and reprints the list
	for (size_t i = 0; i < item_list.size(); i++)
	{
		if (x == startPos.X + 1 && y == startPos.Y + i + 1)
		{
			checked[i] = !checked[i];			//Reverses state on each click
			//printWidget();
		}
	}



}

//Prints the check list
void CheckList2::printWidget()
{
	//Gets the output handle
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Gets the Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	COORD current_pos = ConsoleInfo->dwCursorPosition;

	//Saves the original colors of the screen
	WORD originalColors = ConsoleInfo->wAttributes;


//	printBorder();

	short cursor_pos = current_pos.Y - startPos.Y;
	//Iterates through the items

	short i = 0;
	for (vector<string>::iterator it = item_list.begin(); it != item_list.end(); it++, i++)
	{
		//Set the cursor to the next line
		SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + i + 1 });

		//If the current item is checked
		if (checked[i] == true)
		{
			//White background and black font

			SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			cout << "X " << i + 1 << " " << *it;

			//Restore original colors
			SetConsoleTextAttribute(hout, originalColors);
		}

		//Else if item is not picked
		else
		{
			if (i + 1 == cursor_pos)
				SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			cout << "O " << i + 1 << " " << *it;
			SetConsoleTextAttribute(hout, originalColors);
		}

		//Set the cursor to the end of the line
		SetConsoleCursorPosition(hout, { startPos.X + (short)getWidth() - 1, startPos.Y + i + 1 });


	}


}

void CheckList2::selectIndex(size_t index)
{
	
	checked[index] = true;
}

void CheckList2::deselectIndex(size_t index)
{
	checked[index] = false;
}

void CheckList2::draw(Graphics &g, int left, int top, int layer)
{
	printBorder(g,left,top,layer);
	

	COORD current_pos = getStartPosition();
	
	//Iterates through the items

	short cursor_pos = current_pos.Y - startPos.Y;

	short i = 0;
	for (vector<string>::iterator it = item_list.begin(); it != item_list.end(); it++, i++)
	{
		//Set the cursor to the next line
		g.moveTo(startPos.X + 1, startPos.Y + i + 1);
		//SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + i + 1 });

		//If the current item is checked
		if (checked[i] == true)
		{
			//White background and black font

			g.setBackground(Color::White);
			g.setForeground(Color::Black);
			//SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			
			g.write("X ");
			g.write(convertToString(i + 1));
			g.write(" ");
			g.write(*it);
			//cout << "X " << i + 1 << " " << *it;

			//Restore original colors
			//SetConsoleTextAttribute(hout, originalColors);
			g.setBackground(Color::Black);
			g.setForeground(Color::White);
		}

		//Else if item is not picked
		else
		{
			if (i + 1 == cursor_pos)
				;//SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			g.write("O ");
			g.write(convertToString(i + 1));
			g.write(" ");
			g.write(*it);
			//cout << "O " << i + 1 << " " << *it;
			g.setBackground(Color::Black);
			g.setForeground(Color::White);
			//SetConsoleTextAttribute(hout, originalColors);
		}

		//Set the cursor to the end of the line
		g.moveTo(startPos.X + (short)getWidth() - 1, startPos.Y + i + 1);
		//SetConsoleCursorPosition(hout, { startPos.X + (short)getWidth() - 1, startPos.Y + i + 1 });


	}

}