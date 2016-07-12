#pragma once
#include "Panel.h"
#include "Label.h"

class OptionsContainer : public Panel
{
protected:

	bool* checked;
	int clickedOption;
	int numberOfOptions;


public:
	OptionsContainer(int height, int width, vector<string> _items);


	virtual void draw(Graphics &g, int left, int top, int layer);

	void setSelectedIndex(size_t index);

	size_t getSelectedIndex() const;

	int getSize() { return numberOfOptions; }

	~OptionsContainer();
};