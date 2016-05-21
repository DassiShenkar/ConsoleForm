#include "TextBox.h"

#include <iostream>
#include <wchar.h>
#include <string.h>


//Default Constructor
TextBox::TextBox() :Widget()
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;



	//Initializes the body with spaces
	body = new WCHAR[((getWidth() - 2) * (getHeight() - 2))];
	int end_of_string = ((getWidth() - 2) * (getHeight() - 2));
	for (int i = 0; i <end_of_string; i++)
	{
		body[i] = WCHAR(' ');

	}
	this->printTextBox();
}



TextBox::TextBox(COORD pos, short _width, short _height) : Widget(pos, _width, _height)
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Current console cursor position
	COORD cursorPos = ConsoleInfo->dwCursorPosition;

	//SetConsoleTextAttribute(hout, 0x93&0xDD&0xF5 | 0x0004 | 0x0008);
	SetConsoleCursorPosition(hout, startPos);

	body = new WCHAR[((getWidth() - 2) * (getHeight() - 2))];
	int end_of_string = ((getWidth() - 2) * (getHeight() - 2));
	for (int i = 0; i <end_of_string; i++)
	{
		body[i] = WCHAR(' ');


	}


	this->printTextBox();

}

void TextBox::actOnKeyEvent(KEY_EVENT_RECORD key)
{
	//Take over the output 
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Current console cursor position
	COORD cursorPos = ConsoleInfo->dwCursorPosition;



	if (isPositionLegal(cursorPos))
	{
		//Location in string
		int location = (cursorPos.Y - startPos.Y - 1)*(this->getWidth() - 2) + cursorPos.X - startPos.X - 1;
		int max_size = (getWidth() - 2)*(getHeight() - 2);

		Keys keyPressed;
		keyPressed = determineTypeOfKey(key);
		WCHAR * temp = new WCHAR(' ');

		switch (keyPressed)
		{
		case UP:		//Up Arrow
			if (isPositionLegal({ cursorPos.X,cursorPos.Y - 1 }))
				SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y - 1 });

			break;

		case DOWN:		//Down Arrow
			if (isPositionLegal({ cursorPos.X,cursorPos.Y + 1 }))
				SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y + 1 });

			break;

		case LEFT:		//Left Arrow
			if (isPositionLegal({ cursorPos.X - 1,cursorPos.Y }))
				SetConsoleCursorPosition(s, { cursorPos.X - 1, cursorPos.Y });

			break;

		case RIGHT:		//Right Arrow
			if (isPositionLegal({ cursorPos.X + 1, cursorPos.Y }))
				SetConsoleCursorPosition(s, { cursorPos.X + 1, cursorPos.Y });
			break;

		case BACKSPACE:	//Backspace 
			rePrintText(s, BACKSPACE, location);
			break;

		case SPACEBAR:	//Spacebar 
			rePrintText(s, SPACEBAR, location);
			break;

		case TAB:	//Tab - equals 8 spaces
			rePrintText(s, TAB, location);

		case ENTER: //Enter key
			rePrintText(s, ENTER, location);
			break;

		case DEL: //delete key
			rePrintText(s, DEL, location);
			break;

		case INSERT:
			break;
		case OTHER:
			if (location > max_size - 2)
				break;
			body[location] = key.uChar.UnicodeChar;


			printf("%c", key.uChar.UnicodeChar);

			break;
		default:
			break;
		}
	}
	else if (isPositionLegal({ (startPos.X + 1), (cursorPos.Y + 1) }))
		SetConsoleCursorPosition(s, { (startPos.X + 1), (cursorPos.Y + 1) });
	else
		SetConsoleCursorPosition(s, { (endPos.X - 1), (endPos.Y - 1) });


	//Restore default color settings to console
	SetConsoleTextAttribute(s, originalColors);

}

void TextBox::actOnMouseEvent(MOUSE_EVENT_RECORD mouse)
{
	//Take over the output 
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Current console cursor position
	COORD cursorPos = ConsoleInfo->dwCursorPosition;

	if (mouse.dwButtonState == 0x0001 &&
		mouse.dwMousePosition.X > this->getStartPosition().X
		&& mouse.dwMousePosition.X<this->getEndPosition().X
		&&mouse.dwMousePosition.Y>this->getStartPosition().Y
		&&mouse.dwMousePosition.Y < this->getEndPosition().Y)
		SetConsoleCursorPosition(s, mouse.dwMousePosition);
}


void TextBox::rePrintText(HANDLE &hout, Keys key, int location)
{
	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save the current cursor position
	COORD old_cursor_pos = ConsoleInfo->dwCursorPosition;



	//int chars_to_end_line = (this->getWidth()) - (old_cursor_pos.X - startPos.X+1);


	//Gets the total size of the body 
	int max_length = (this->getWidth() - 2)* (this->getHeight() - 2);


	//An auxilliary temporary array
	PWCHAR temp_array = new WCHAR[max_length];
	for (int i = 0; i < max_length; i++)
	{
		temp_array[i] = ' ';
	}


	switch (key)
	{
	case BACKSPACE:
		if (location == 0)
			return;


		for (int i = 0; i < max_length - 1; i++)
		{
			if (i < location - 1)
			{
				temp_array[i] = body[i];
			}
			else if (i >= location - 1)
			{
				temp_array[i] = body[i + 1];
			}

		}

		temp_array[max_length - 1] = ' ';
		temp_array[max_length] = ' ';

		SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });
		for (int i = 0; i < max_length - 1; i++)
		{


			body[i] = temp_array[i];

			if ((i % (getWidth() - 2)) == 0 && i != 0)
			{
				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				SetConsoleCursorPosition(hout, { startPos.X + 1, ConsoleInfo->dwCursorPosition.Y + 1 });
			}

			printf("%c", body[i]);

			if (!isPositionLegal({ old_cursor_pos.X - 1, old_cursor_pos.Y }))
				SetConsoleCursorPosition(hout, { endPos.X - 1,old_cursor_pos.Y - 1 });




		}
		if (isPositionLegal({ old_cursor_pos.X - 1, old_cursor_pos.Y }))
			SetConsoleCursorPosition(hout, { old_cursor_pos.X - 1,old_cursor_pos.Y });
		else
			SetConsoleCursorPosition(hout, { endPos.X - 1,old_cursor_pos.Y - 1 });



		break;
	case SPACEBAR:
		for (int i = 0; i < max_length - 1; i++)
		{
			if (i < location + 1)
			{
				temp_array[i] = body[i];
			}
			else if (i == location + 1)
			{
				temp_array[i] = ' ';
			}
			else
			{
				temp_array[i] = body[i - 1];
			}
		}

		temp_array[max_length - 1] = body[max_length - 1];

		SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });
		for (int i = 0; i < max_length - 1; i++)
		{
			body[i] = temp_array[i];
			if ((i % (getWidth() - 2)) == 0 && i != 0)
			{
				GetConsoleScreenBufferInfo(hout, ConsoleInfo);
				SetConsoleCursorPosition(hout, { startPos.X + 1, ConsoleInfo->dwCursorPosition.Y + 1 });
			}
			printf("%c", body[i]);
		}

		if (isPositionLegal({ old_cursor_pos.X + 1, old_cursor_pos.Y }))
			SetConsoleCursorPosition(hout, { old_cursor_pos.X + 1,old_cursor_pos.Y });
		else
			SetConsoleCursorPosition(hout, { startPos.X + 1,old_cursor_pos.Y + 1 });

		break;

	case TAB:
		for (int i = 0; i < 8; i++)
		{
			rePrintText(hout, SPACEBAR, location);
		}
		break;

	case ENTER:

		for (int i = 0; i < getWidth() - 2; i++)
		{
			rePrintText(hout, SPACEBAR, location - 1);


		}
		break;
	case DEL:
		rePrintText(hout, BACKSPACE, location + 1);

		break;

	case INSERT:
		rePrintText(hout, BACKSPACE, location + 1);

		break;

	default:
		break;
	}

}

void TextBox::printTextBox()
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Set cursor to top left corner of text box
	SetConsoleCursorPosition(hout, startPos);

	SetConsoleTextAttribute(hout, 0x93 & 0xDD & 0xF5 | 0x0004 | 0x0008);


	for (short i = 0; i < getHeight(); i++)
	{
		for (short j = 0; j < getWidth(); j++)
		{
			cout << ' ';
		}
		SetConsoleCursorPosition(hout, { startPos.X, startPos.Y + i + 1 });
	}

	SetConsoleCursorPosition(hout, startPos);

	//Prints the top boundary
	for (int i = 0; i < width; i++)
	{
		printf("\xcd");
	}

	//Prints the right and left boundaries
	for (int i = 0; i < height; i++)
	{

		printf("\n");
		short startX = startPos.X;
		short startY = startPos.Y + i;
		SetConsoleCursorPosition(hout, { startX,startY });
		printf("\xba");

		//Prints the bootom boundary
		if (i == height - 1)
		{
			for (int i = 0; i < width; i++)
			{
				printf("\xcd");
			}
		}


		short endX = startPos.X + width;
		short endY = startPos.Y + i;

		//Sets the consoleCursor position to the end
		SetConsoleCursorPosition(hout, { endX,endY });
		printf("\xba");

		SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });

	}

}



