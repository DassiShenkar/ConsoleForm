#include "ConsoleHandler.h"
#include "CheckList.h"
#include "RadioList.h"
#include "Label.h"
#include "TextBox.h"
#include "ColorDecorator.h"
#include "BorderDecorator.h"
#include "ComboBox.h"
#include "WidgetDecorator.h"
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

	Label* label = new Label({ 30,2 }, "My Form");
	CheckList* checkList = new CheckList({ 15,10 }, items);
	ComboBox* comboBox = new ComboBox({ 2,20 }, items);
	RadioList* radioList = new RadioList({ 10,2 }, items);
	TextBox* textBox = new TextBox({ 45,5 },10,10);
	console->attach(label);
	console->attach(checkList);
	console->attach(comboBox);
	console->attach(radioList);
	console->attach(textBox);
	console->start();
	return 0;
}