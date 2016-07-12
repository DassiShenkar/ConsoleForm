#include "CheckList.h"
#include <iostream>
#include <string>
#include "Button.h"
using namespace std;


//A constructor that recieves the dimensions and the list of items
CheckList::CheckList(int _height, int _width, vector<string> _items) : OptionsContainer(_height, _width, _items)
{

}


void CheckList::mousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < numberOfOptions; i++)
	{
		if (y - getStartY() - 1 == i)
			checked[i] = !checked[i];

	}
}

void CheckList::selectIndex(size_t index)
{
	checked[index - 1] = true;
}

