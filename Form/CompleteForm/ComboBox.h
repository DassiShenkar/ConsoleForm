#pragma once
#include "OptionsContainer.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

class ComboBox : public Panel
{
private:
	size_t index;
	bool drop_down;
	Label header;
	OptionsContainer body;

public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string> options);

	void addControl(Control& control, int x, int y) = delete;

	void mousePressed(int x, int y, bool isLeft);


	//virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t i);

	size_t getSelectedIndex() const;
};