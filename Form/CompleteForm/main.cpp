#include "CheckList.h"
#include "RadioList.h"
#include "Label.h"
#include "TextBox.h"
#include "Panel.h"
#include "ComboBox.h"
#include "Form.h"
#include "Widget.h"
#include <Windows.h>
#include "NumericBox.h"


using namespace std;

struct Listener : public MouseListener {
	void MousePressed(Widget &widget, int x, int y, bool is_left) {
		exit(1);
	}
};

int main()
{
	Form* form = Form::getInstance({ 5,5 }, 70, 70);
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
	NumericBox * numericbox = new NumericBox(10, 0, 10);
	form->addControl(panel, { 2,2 });
	panel->addControl(label, { 5,5 });
	panel->addControl(textBox, { 10, 12 });
	panel->addControl(numericbox, { 5,20 });
	numericbox->addControls();
	//panel->addControl(comboBox, { 5,20 });
	panel->addControl(radioList, { 35,5 });
	panel->addControl(checkList, { 35,20 });
	label->setText("Hello World");
	panel->printWidget();
	form->run();
	return 0;
}