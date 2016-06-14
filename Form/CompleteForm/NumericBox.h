#pragma once

#include "Panel.h"
#include "Button.h"
#include "Label.h"



class NumericBox : public Panel 
{
private:
	int min_val;
	int max_val;
	vector<Widget*> items;
	
	
public:
	Label* label;
	NumericBox(int width);
	NumericBox(int width, int min, int max);
	void printWidget() const;
	void MousePressed(Button &button, int x, int y, bool is_left);
	void addControls();
	~NumericBox();
};