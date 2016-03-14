#include "TextBox.h"

#include <iostream>


//Default Constructor
TextBox::TextBox() :Widget()
{
	this->PrintWidget(startPos);
}



TextBox::TextBox(COORD pos, short _width, short _height) : Widget(pos, _width, _height), content(" ")
{
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
	int string_index = (cursorPos.Y - this->getStartPosition().Y) + cursorPos.X;

	if (isPositionLegal(cursorPos))
	{
		Keys keyPressed;
		keyPressed = determineTypeOfKey(key);
		switch (keyPressed)
		{
		case UP:		//Up Arrow
			SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y - 1 });
			if (!isPositionLegal(ConsoleInfo->dwCursorPosition))
				SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y + 1 });
			break;

		case DOWN:		//Down Arrow
			SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y + 1 });
			if (!isPositionLegal(ConsoleInfo->dwCursorPosition))
				SetConsoleCursorPosition(s, { cursorPos.X, cursorPos.Y - 1 });
			break;

		case LEFT:		//Left Arrow
			SetConsoleCursorPosition(s, { cursorPos.X - 1, cursorPos.Y });
			if (!isPositionLegal(ConsoleInfo->dwCursorPosition))
				SetConsoleCursorPosition(s, { cursorPos.X + 1, cursorPos.Y });
			break;

		case RIGHT:		//Right Arrow
			SetConsoleCursorPosition(s, { cursorPos.X + 1, cursorPos.Y });
			if (!isPositionLegal(ConsoleInfo->dwCursorPosition))
				SetConsoleCursorPosition(s, { cursorPos.X - 1, cursorPos.Y });
			break;

		case BACKSPACE:	//Backspace - acts the same as LEFT arrow
			SetConsoleCursorPosition(s, { cursorPos.X - 1, cursorPos.Y });
			if (!isPositionLegal(ConsoleInfo->dwCursorPosition))
				SetConsoleCursorPosition(s, { cursorPos.X + 1, cursorPos.Y });
			break;
		case TAB:	//Backspace - acts the same as LEFT arrow
			if (!isPositionLegal({ SHORT(cursorPos.X + 8), cursorPos.Y }))
				SetConsoleCursorPosition(s, { cursorPos.X + 8, cursorPos.Y });


			break;

		case OTHER:



			printf("%c", key.uChar.UnicodeChar);
			break;
		default:
			break;
		}

	}
	else if (isPositionLegal({ cursorPos.X - 1, cursorPos.Y + 2 }))
	{
		SetConsoleCursorPosition(s, { this->getStartPosition().X + 1 ,cursorPos.Y + 1 });
		if (cursorPos.Y >= this->getEndPosition().Y)
			SetConsoleCursorPosition(s, { this->getStartPosition().X ,cursorPos.Y - 1 });

		if (key.bKeyDown)
		{
			printf("%c", key.uChar.UnicodeChar);
		}
	}

	else
	{
		if (cursorPos.X <= this->getStartPosition().X)
			SetConsoleCursorPosition(s, { this->getStartPosition().X + 1 ,cursorPos.Y });
		else if (cursorPos.X >= this->getEndPosition().X)
			SetConsoleCursorPosition(s, { this->getStartPosition().X - 1 ,cursorPos.Y });
		else if (cursorPos.Y <= this->getStartPosition().Y)
			SetConsoleCursorPosition(s, { this->getStartPosition().X ,this->getStartPosition().Y + 1 });
		else if (cursorPos.Y >= this->getEndPosition().Y)
			SetConsoleCursorPosition(s, { this->getStartPosition().X ,this->getEndPosition().Y - 2 });
		else if (cursorPos.Y == this->getEndPosition().Y + 1)
			SetConsoleCursorPosition(s, { this->getStartPosition().X + 1 ,cursorPos.Y - 2 });

	}


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





/*
void TextBox::printTextBox(COORD pos, short  w , short h) const
{
//Take over the output
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

//Set cursor to top left corner of text box
SetConsoleCursorPosition(hout, startPos);
for (int i = 0; i < width; i++)
{
printf("\xcd");
}
for (int i = 0; i < height; i++)
{

printf("\n");
short startX = pos.X;
short startY = pos.Y + i;
SetConsoleCursorPosition(hout, { startX,startY });
printf("\xba");
if (i == height - 1)
{
for (int i = 0; i < width; i++)
{
printf("\xcd");
}
}
short endX = pos.X + width;
short endY = pos.Y + i;
SetConsoleCursorPosition(hout, { endX,endY });
printf("\xba");

SetConsoleCursorPosition(hout, { startPos.X+1,startPos.Y+1 });
//printf("Click on the text box to start typing ");
}

}*/

/*
string operator+=(string s, WCHAR c)
{


}*/
