#include "RadioList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
RadioList::RadioList(int _height, int _width, vector<string> _items) : OptionsContainer(_height, _width, _items)
{

}


void RadioList::mousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < numberOfOptions; i++)
	{
		if (y - getStartY() - 1 == i)
			checked[i] = true;
		else
			checked[i] = false;

	}
}

