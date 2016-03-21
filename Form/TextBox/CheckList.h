#pragma once

#include <iostream>
#include <Windows.h>
#include "Widget.h"
#include "LinkedList.h"
#include <string>

using namespace std;

class CheckList : public Widget
{
private:
	LinkedList<string&>* item_list;
	bool * checked;

public:
	CheckList();
	CheckList(COORD, LinkedList<string&>*);
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);
	void printCheckList() const;

};
