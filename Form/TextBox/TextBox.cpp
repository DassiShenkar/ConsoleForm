#include "TextBox.h"

#include <iostream>
#include <wchar.h>
#include <string.h>


//Default Constructor
TextBox::TextBox() :Widget()
{
	
	
	this->PrintWidget(startPos);
}



TextBox::TextBox(COORD pos, short _width, short _height) : Widget(pos, _width, _height)
{
	
	body = new WCHAR[((getWidth() - 2) * (getHeight() - 2))];
	int end_of_string = ((getWidth() - 2) * (getHeight() - 2));
	for (int i = 0; i <end_of_string ; i++)
	{
		body[i] = WCHAR(' ');
	}

	
	this->PrintWidget(pos);
	
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
		int location = ((cursorPos.Y - startPos.Y - 1)*this->getWidth()) + cursorPos.X - startPos.X - 1;

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

		case BACKSPACE:	//Backspace - acts the same as LEFT arrow
			if (isPositionLegal({ cursorPos.X - 1, cursorPos.Y }))
				SetConsoleCursorPosition(s, { cursorPos.X - 1, cursorPos.Y });

			break;
		case TAB:	//Tab - equals 8 spaces
			if (isPositionLegal({ (cursorPos.X + 8), cursorPos.Y }))
				SetConsoleCursorPosition(s, { cursorPos.X + 8, cursorPos.Y });


			break;

		case OTHER:

			body[location] = key.uChar.UnicodeChar;
			printf("%c", key.uChar.UnicodeChar);
			break;
		default:
			break;
		}
	}
	else if (isPositionLegal({ (startPos.X + 1), (cursorPos.Y + 1) }))
		SetConsoleCursorPosition(s,{ (startPos.X + 1), (cursorPos.Y + 1) });
	else
		SetConsoleCursorPosition(s, { (endPos.X-1), (endPos.Y-1) });


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







