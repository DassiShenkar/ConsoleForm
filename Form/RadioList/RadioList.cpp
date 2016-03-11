#include <windows.h>
#include "RadioList.h"


RadioList::RadioList()
{
}

RadioList::RadioList(int x, int y, string labels[])
{
	int i = 0;
	HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(s, ConsoleInfo);
	WORD originalColors = ConsoleInfo->wAttributes;
	COORD position;
	CONSOLE_CURSOR_INFO console;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(s, position);
	SetConsoleTextAttribute(s, FOREGROUND_GREEN);
	console.bVisible = FALSE;
	SetConsoleCursorInfo(s, &console);
	while (!labels[i].empty()) {
		printf("%s%s/n", "[ ]", labels[i]);
		i++;
	}
	SetConsoleTextAttribute(s, originalColors);

}


RadioList::~RadioList()
{
}
