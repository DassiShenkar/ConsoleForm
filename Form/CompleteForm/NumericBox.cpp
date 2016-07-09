#include "NumericBox.h"
#include <sstream>
using namespace std;

NumericBox::NumericBox(int _width, int _min, int _max) : Panel(5, _width), minus(*(new Button(3)))
, plus(*(new Button(3))), label(3)
{



	min = _min;
	max = _max;
	currentValue = 0;
	string result = convertToString(0);
	label.setText(result);
	minus.setText("-");
	minus.addMouseListener(this);
	plus.setText("+");
	plus.addMouseListener(this);
	this->addControl(plus, 2, 3);
	this->addControl(minus, 6, 3);
	this->addControl(label, 4, 1);

}



string NumericBox::convertToString(int val)
{
	string result = "";
	string temp = "";
	if (val < 0)
	{
		temp.append("-");
		val = -val;
	}
	while (val > 0)
	{

		temp.append(to_string(val % 10));
		val /= 10;
	}
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		result += (temp.at(i));
	}
	return result;
}


void NumericBox::mousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setFocus(this);
	if (control == &plus && isLeft)
	{
		label.setText(convertToString(++currentValue));
	}
	else
	{
		label.setText(convertToString(--currentValue));
	}
}

NumericBox::~NumericBox()
{
	for (int i = 0; i < numberOfItems; i++) {
		delete items[i];
	}
}