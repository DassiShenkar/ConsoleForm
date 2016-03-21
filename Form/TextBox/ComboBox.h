#pragma once
#include "Widget.h"
#include <Windows.h>
#include "LinkedList.h"
#include <string>
using namespace std;


class ComboBox : public Widget
{
private:
	LinkedList<string&> item_list;
	string header;
	bool drop_down;
	void clearLabel();
	void clearBody();
public:

	ComboBox();
	ComboBox(COORD, LinkedList<string&>*);
	string getHeader() const { return header; }
	void setHeader(string _header) { header = _header; }
	void printComboBox();
	void actOnKeyEvent(KEY_EVENT_RECORD);
	void actOnMouseEvent(MOUSE_EVENT_RECORD);
};
