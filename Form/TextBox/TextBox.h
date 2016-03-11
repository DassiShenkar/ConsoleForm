#pragma once

#include <Windows.h>

class TextBox
{
private:
	COORD startPos;
	int width, height;

public:
	TextBox();
	TextBox(COORD pos, int width, int height);
};
#pragma once
