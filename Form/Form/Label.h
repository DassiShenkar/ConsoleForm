#pragma once

#include <Windows.h>

class Label
{
private:
	int x, y;
	char * text;

public:
	Label();
	Label(int, int, char * text);

};

