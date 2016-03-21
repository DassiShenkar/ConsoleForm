#include "ComboBox.h"
#include <iostream>
#include <string>
using namespace std;

ComboBox::ComboBox() : Widget(), header("Select Item"), drop_down(false) {}

ComboBox::ComboBox(COORD start, LinkedList<string&>* items): Widget(start, 20 ,items->getCount()+4), 
item_list(*items), header("Select Item"), drop_down(false)
{
	printComboBox();
}

void ComboBox::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	;
}
void ComboBox::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	if (mouse.dwButtonState == 0x0001 &&
		mouse.dwMousePosition.X == startPos.X + 1 &&
		mouse.dwMousePosition.Y == startPos.Y + 1)
	{
		if (drop_down == false)
		{
			drop_down = true;
			printComboBox();
		}
		else
		{
			drop_down = false;
			printComboBox();
		}

	}
	else if (mouse.dwButtonState == 0x0001 &&
		mouse.dwMousePosition.X == startPos.X + 1)
		
	{
		for (int i = 0; i < item_list.getCount(); i++)
		{
			if (drop_down == false)
			{

				;

			}
			else
			{
				if (mouse.dwMousePosition.Y == startPos.Y + i + 3)
				{
					this->setHeader(item_list[i].getData());
					clearLabel();
					drop_down = false;
					printComboBox();
				}
			}
		}
	}
}

void ComboBox::printComboBox()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;

	SetConsoleCursorPosition(hout, startPos);
	//Prints the header part
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	SetConsoleCursorPosition(hout, { startPos.X,startPos.Y+1});
	cout << '|' << "O| " << header;
	SetConsoleCursorPosition(hout, { startPos.X+getWidth()-1,startPos.Y+1 });
	cout<<'|';
	SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + 2 });
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}

	if (drop_down == true)
	{
		//Prints the body
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + 3 });
		int body_height = item_list.getCount();

		for (short i = 0; i < body_height; i++)
		{
			cout << "|" << i + 1 << "| " << item_list[i].getData();
			SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1,startPos.Y + i + 3 });
			cout << '|';
			SetConsoleCursorPosition(hout, { startPos.X ,startPos.Y + i + 4 });
		}
		for (int i = 0; i < width; i++)
		{
			cout << "-";
		}
	}
	else
	{
		clearBody();
	}
		
}

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
		for (int i = 0; i < width; i++)
		{
			cout << " ";
		}
		SetConsoleCursorPosition(hout, { startPos.X + getWidth() - 1,startPos.Y + i + 3 });
		cout << ' ';
		SetConsoleCursorPosition(hout, { startPos.X ,startPos.Y + i + 4 });
	}
	for (int i = 0; i < width; i++)
	{
		cout << " ";
	}

}