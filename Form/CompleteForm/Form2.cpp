#include "Form2.h"

Form2* Form2::_instance = 0;

Form2::Form2(COORD position, int _width, int _height) : panel(_width, _height), engine(new Engine())
{
	panel.setStartPosition(position);
	panel.printWidget();
	engine->attach(&panel);
}