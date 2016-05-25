#include "Form.h"

Form* Form::_instance = 0;

Form::Form(COORD position, int _width,int _height) : panel(_width,_height),console(ConsoleHandler::getInstance())
{
	panel.setStartPosition(position);
	panel.printWidget();
	console->attach(&panel);
}