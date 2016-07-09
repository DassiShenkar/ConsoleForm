#include "RadioList.h"
#include <iostream>
#include <string>
#include "Keys.h"
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
RadioList::RadioList(int _height, int _width, vector<string> _items) : OptionsContainer(_height + 2, _width, _items)
{
	for (vector<Control*>::iterator it = items.begin(); it != items.end(); it++)
	{
		static_cast<Button*>(*it)->addMouseListener(this);
	}
}

/*
//A method that responds only to up and down arrows from the keybord
void RadioList2::keyDown(KEY_EVENT_RECORD key)
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
}*/




/*
//Prints the Radio List
void RadioList2::printWidget()
{

//Gets the output handle
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

//Gets the console's info
CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
GetConsoleScreenBufferInfo(hout, ConsoleInfo);

//Save the original colors of the console
WORD originalColors = ConsoleInfo->wAttributes;

//printBorder();
//Iterates through the item list and prints the items
short i = 0;
for (vector<string>::iterator it = item_list.begin(); it != item_list.end(); it++, i++)
{

SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + i + 1 });
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
}*/



string RadioList::convertToString(int val)
{
	string result = "";
	string temp = "";
	if (val < 0)
	{
		temp.append("-");
		val = -val;
	}
	while (val > 0)
	{

		temp.append(to_string(val % 10));
		val /= 10;
	}
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		result += (temp.at(i));
	}
	return result;
}
