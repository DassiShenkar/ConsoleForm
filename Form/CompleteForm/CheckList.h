#pragma once

#include <iostream>
#include <Windows.h>
#include "OptionsContainer.h"
#include <vector>
#include <string>

using namespace std;


class CheckList : public OptionsContainer
{

public:

	//A constructor that recieves the starting coordinate and the list of items
	CheckList(int _height, int _width, vector<string>);

	virtual void mousePressed(int x, int y, bool isLeft);

	void selectIndex(size_t index);


};
