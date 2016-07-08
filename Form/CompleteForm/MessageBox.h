#pragma once
#include <string>
#include <Windows.h>
#include <iostream>

class MessageBox
{
private:

public:
	MessageBox() {};
	void SetText(string text);
	void SetTitle(string title);

	~MessageBox();
};

