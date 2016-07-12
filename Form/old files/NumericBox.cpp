#include "NumericBox.h"
#include <sstream>
using namespace std;

NumericBox::NumericBox(int _width, int _min, int _max, int value) : Panel(_width, 10), minus(*(new Button(3)))
, plus(*(new Button(3))), label(3)
{
	
	min = _min;
	max = _max;
	currentValue = value;
	string result = convertToString(value);
	label.setText(result);
	minus.setText("-");
	minus.addMouseListener(this);
	plus.setText("+");
	plus.addMouseListener(this);
	this->addControl(&plus, { 2,5 });
	this->addControl(&minus, { 6,5 });
	this->addControl(&label, { 4,2 });

}



string NumericBox::convertToString(int val)
{
	string result = "" ;
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
	for (int i = temp.length()-1; i >= 0; i--)
	{
		result+=(temp.at(i));
	}
	return result;
}


void NumericBox::actOnMouseClick(Widget* widget, MOUSE_EVENT_RECORD mouse)
{
	if (widget == &plus)
	{
		label.setText(convertToString(++currentValue));
	}
	else
	{
		label.setText(convertToString(--currentValue));
	}
}