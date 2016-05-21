#pragma once
#include <iostream>
#include <Windows.h>
#include "Widget.h"
#include "LinkedList.h"
#include <string>


class NumericBox :public Widget
{
private:
	int value;

public:
	NumericBox(COORD,int _value = 0);
	int getValue() const { return value; }
	void setValue(int _value);
};