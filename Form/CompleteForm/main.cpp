#include "ConsoleHandler.h"
#include "CheckList.h"
#include "RadioList.h"
#include "Label.h"
#include "TextBox.h"
#include "Panel.h"
#include "ComboBox.h"

#include "Widget.h"
#include <Windows.h>



using namespace std;

int main()
{
	ConsoleHandler* console = ConsoleHandler::getInstance();
	vector<string>* items = new vector<string>;
	items->push_back("Item 1");
	items->push_back("Item 2");
	items->push_back("Item 3");
	items->push_back("Item 4");

	Panel* panel = new Panel(30, 30);
	Label *label = new Label(10);
	TextBox* textBox = new TextBox(10, 5);

	panel->addControl(label, { 5,5 });
	panel->addControl(textBox, { 10, 10 });
	label->setText("Hello World");
	panel->printWidget();
	console->attach(panel);
	console->start();
	return 0;
}