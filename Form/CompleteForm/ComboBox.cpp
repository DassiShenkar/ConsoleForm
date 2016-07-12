#include "ComboBox.h"
#include <iostream>
#include <string>
using namespace std;

//A constructor that gets the starting coordinate of the Combo Box and the list of items
ComboBox::ComboBox(int _width, vector<string> _items) : OptionsContainer(_items.size() + 2, _width, _items), drop_down(false)
{
	header = new Button(_width);
	header->setText("Select");
	header->addMouseListener(this);
	Panel::addControl(*header, 0, -3);
}

void ComboBox::buttonMousePressed(Control* control, int x, int y, bool isLeft)
{
	if (control == header)
	{
		drop_down = !drop_down;
		return;
	}
		
	OptionsContainer::buttonMousePressed(control,x,y,isLeft);
}






void ComboBox::draw(Graphics &g, int left, int top, int layer)
{

	printBorder(g, left, top, layer);


	g.moveTo(getStartX() + 1, getStartY() + 1);
	//SetConsoleCursorPosition(hout, { startPos.X + 1,startPos.Y + 1 });
	g.setBackground(Color::White);
	g.setForeground(Color::Black);
	//SetConsoleTextAttribute(hout, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	g.write("O| ");
	g.write(header->getText());

	g.setBackground(Color::Black);
	g.setForeground(Color::White);

	g.moveTo(getStartX() + 1, getStartY() + 2);
	for (int i = 0; i < width - 1; i++)
	{
		g.write("-");
	}


	//If the drop down menu should be open
	if (drop_down == true)
	{
		//Prints the body
		g.moveTo(getStartX() + (short)border, getStartY() + 3);
		int body_height = items.size() - 1;

		//GetConsoleScreenBufferInfo(hout, ConsoleInfo);
		//short cursor_pos = current_pos.Y - startPos.Y;
		for (short i = 0; i < body_height; i++)
		{

	
			g.write(convertToString(i + 1));
			g.write("| ");
			g.write(static_cast<Button*>(items.at(i + 1))->getText());
			g.moveTo(getStartX() + (short)border, getStartY() + i + 4);

		}

	}

	

}