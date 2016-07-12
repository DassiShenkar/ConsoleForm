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




void NumericBox::buttonMousePressed(Control* control, int x, int y, bool isLeft)
{
	Control::setGlobalFocus(this);
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