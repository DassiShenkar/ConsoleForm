#pragma once
#include "OptionsContainer.h"
#include "Button.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

class ComboBox : public OptionsContainer
{
private:
	size_t index;
	bool drop_down;
	Button* header;
	
public:

	//A constructor that gets the starting coordinate of the Combo Box and the list of items
	ComboBox(int _width, vector<string> options);

	void addControl(Control& control, int x, int y) = delete;

	void buttonMousePressed(Control * control, int x, int y, bool isLeft);

	virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t i) { index = i; };

	size_t getSelectedIndex() const { return index; }
};