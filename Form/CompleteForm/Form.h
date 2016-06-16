#pragma once
#include "Panel.h"
#include "ConsoleHandler.h"



class Form
{
private:
	Panel panel;
	ConsoleHandler* console;
	static Form* _instance;
	Form(COORD position, int _width = 50, int _height = 50);
	Form(const Form&);
	Form& operator=(const Form&);

public:
	static Form* getInstance(COORD position, int _width = 50, int _height = 50)
	{
		if (_instance == 0)
		{
			_instance = new Form(position, _width,_height);
		}
		return _instance;
	}
	void run() { console->start(); panel.printWidget(); }
	void addControl(Widget* control, COORD position) { panel.addControl(control, position); }

};
