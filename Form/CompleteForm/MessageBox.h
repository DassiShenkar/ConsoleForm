#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MessageBox : public Panel2
{
public:
	MessageBox(int height, int width);
	~MessageBox();

	void setTtl(string ttl);
	void setMsg(string msg);

};

