#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max) : Panel(3, width), text(*new Label(3))
{
	text.setText(convertToString(0));
	text.setBorder(BorderType::None);
	Button* minus = new Button(width / 2 - 2);
	minus->setText("-");
	minus->setBorder(BorderType::Single);
	minus->addMouseListener(this);
	Button* plus = new Button(width / 2 - 2);
	plus->setText("+");
	plus->setBorder(BorderType::Single);
	plus->addMouseListener(this);

	Panel::addControl(text, width / 2 - 1, getStartY());
	Panel::addControl(*minus, 1, getStartY() + 2);
	Panel::addControl(*plus, width / 2 + 1, getStartY() + 2);


}

void NumericBox::buttonMousePressed(Control* control, int x, int y, bool isLeft)
{
	if (static_cast<Button*>(control)->getText().compare("-") == 0)
		setValue(--value);
	else
		setValue(++value);
}

void NumericBox::setValue(int val)
{
	value = val;
	text.setText(convertToString(value));

}