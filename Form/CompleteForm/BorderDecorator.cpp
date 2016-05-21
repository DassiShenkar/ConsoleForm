#include "BorderDecorator.h"



void BorderDecorator::printWidget(COORD startPos) const
{
	WidgetDecorator::printWidget(startPos);
	if (getBorderType().compare("single") == 0)		//Single border
	{
		/*
			Add single border line
		*/
	}
	else
	{
		/*
		Add double border line
		*/
	}
}