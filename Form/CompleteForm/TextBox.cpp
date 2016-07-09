#include "TextBox.h"

#include <iostream>
#include <wchar.h>
#include <string.h>

TextBox::TextBox(int _width) : TextBox(1, _width)
{

}
TextBox::TextBox(int _height, int _width) : Control(_height, _width)
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

}

void TextBox::keyDown(KEY_EVENT_RECORD key)
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

void TextBox::mousePressed(int x, int y)
{
	Control::setFocus(this);
	//Take over the output 
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);

	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);

	//Save original color settings
	WORD originalColors = ConsoleInfo->wAttributes;

	//Current console cursor position
	COORD cursorPos = ConsoleInfo->dwCursorPosition;

	if (
		x > this->getStartPosition().X
		&& x<this->getEndPosition().X
		&& y>this->getStartPosition().Y
		&& y < this->getEndPosition().Y)
		SetConsoleCursorPosition(s, { short(x), short(y) });
}


void TextBox::rePrintText(HANDLE &hout, Keys key, int location)
{
	//Console's info
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hout, ConsoleInfo);

	//Save the current cursor position
	COORD old_cursor_pos = ConsoleInfo->dwCursorPosition;


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

void TextBox::printWidget()
{
	//Take over the output 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//	printBorder();
	SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });
	int h = 0;
	for (short i = 0; i < getHeight() - 2; i++)
	{
		for (short j = 0; j < getWidth() - 2; j++)
		{
			printf("%c", body[h]);
			h++;
		}
		SetConsoleCursorPosition(hout, { startPos.X + 1, startPos.Y + i + 2 });
	}

}

/*A function that checks if the position of the console cursor
is in the boundaries of the textBox
*/
bool TextBox::isPositionLegal(COORD pos)
{
	if ((pos.X > this->getStartPosition().X && pos.X<this->getEndPosition().X) &&
		(pos.Y>this->getStartPosition().Y && pos.Y < this->getEndPosition().Y)
		)
		return true;

	return false;
}

void TextBox::setText(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		body[i] = text[i];
	}

	printWidget();
}

string TextBox::getText() const
{
	string text;
	int body_length = ((getWidth() - 2) * (getHeight() - 2));
	for (int i = 0; i < body_length; i++)
	{
		text.push_back(body[i]);
	}
	return text;
}



