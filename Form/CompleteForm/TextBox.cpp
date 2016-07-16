#include "TextBox.h"


TextBox::TextBox(int width): Button(width)
{
	setText("");
	addListener(static_cast <MouseListener*>(this));
	addListener(static_cast <KeyboardListener*>(this));
	
}




void TextBox::keyDown(KEY_EVENT_RECORD key)
{
	cursorVisibility(true);
	Keys k = determineTypeOfKey(key);
	string temp;
	int replace;
	switch (k)
	{
	case Keys::BACKSPACE :
		temp = getText();
		replace = getCursorX() - getStartX()-2;
		if (replace < 0)
			break;
		temp.erase(temp.begin()+replace);
		setText(temp);
		setCursorPosition(getCursorX() - 1, getCursorY());
		break;

	case Keys::DEL:
		temp = getText();
		replace = getCursorX() - getStartX()-1;
		if (replace < 0)
			break;
		temp.erase(temp.begin() + replace);
		setText(temp);
		
		break;

	case Keys::LEFT:
		if (getCursorX() - getStartX() <= 1)
			break;
		setCursorPosition(getCursorX() - 1, getCursorY());

		break;

	case Keys::RIGHT:
		if (getCursorX() - getStartX() >= getText().size()+1)
			break;
		setCursorPosition(getCursorX() + 1, getCursorY());
		break;

	case Keys::SPACEBAR:
		temp = getText();
		replace = getCursorX() - getStartX();
		if (replace < 0)
			break;
		temp.insert(temp.begin() + replace, ' ');
		setText(temp);
		break;

	case Keys::OTHER:

		temp = getText();
		replace = getCursorX() - getStartX();
		if (replace < 0)
			break;
		temp.insert(temp.begin() + replace, key.uChar.AsciiChar);
		setText(temp);
		break;
	}

	
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	
	setCursorPosition(x, y);
	this->cursorVisibility(true);
	
}

void TextBox::mousePressed(Control* control, int x, int y, bool isLeft)
{
	setCursorPosition(x, y);
}

void TextBox::focusEvent()
{
	cursorX = startX+1;
	cursorY = startY+1;
}



