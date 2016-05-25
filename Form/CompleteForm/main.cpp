#include "CheckList.h"
#include "RadioList.h"
#include "Label.h"
#include "TextBox.h"
#include "Panel.h"
#include "ComboBox.h"
#include "Form.h"
#include "Widget.h"
#include <Windows.h>



using namespace std;

int main()
{
	Form* form = Form::getInstance({ 5,5 },70,70);
	//ConsoleHandler* console = ConsoleHandler::getInstance();
	vector<string>* items = new vector<string>;
	items->push_back("Item 1");
	items->push_back("Item 2");
	items->push_back("Item 3");
	items->push_back("Item 4");

	Panel* panel = new Panel(60, 40);
	Label *label = new Label(10);
	TextBox* textBox = new TextBox(10, 5);
	//ComboBox* comboBox = new ComboBox(20, items);
	RadioList* radioList = new RadioList(20, 10, items);
	CheckList * checkList = new CheckList(20, 10, items);
	form->addControl(panel, { 2,2 });
	panel->addControl(label, { 5,5 });
	panel->addControl(textBox, { 10, 12 });
	//panel->addControl(comboBox, { 5,20 });
	panel->addControl(radioList, { 35,5 });
	panel->addControl(checkList, { 35,20 });
	label->setText("Hello World");
	panel->printWidget();
	
	form->run();
	//console->attach(panel);
	//console->start();
	return 0;
}