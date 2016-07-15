#include <string>
#include "EventEngine.h"
#include "TextBox.h"
#include "Label.h"
#include "Button.h"
#include "Panel.h"
#include "NumericBox.h"
#include "RadioList.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "MouseListener.h"
#include "Messagebox.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control *, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Red);
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
	Label lName(20);
	lName.setText("Name: ");

	Label lAddress(20);
	lAddress.setText("Address:");
	Label lCountry(20);
	lCountry.setText("Counrty:");
	Label lSex(20);
	lSex.setText("Sex:");
	Label lInterests(20);
	lInterests.setText("Interests:");
	Label lAge(20);
	lAge.setText("Age:");
	TextBox tName(20);
	tName.setText("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	TextBox tAddress(25);
	tAddress.setText("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);

	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
	MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.setText("Submit");
	bSubmit.addListener(&listener);
	bSubmit.setBorder(BorderType::Double);

	Messagebox msgbox(10, 25);
	msgbox.setTtl("Error");
	msgbox.setMsg("stupid isLeft bug");

	Panel main;
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);

	main.addControl(nAge, 25, 20);

	main.addControl(bSubmit, 1, 22);

	main.addControl(msgbox, 11, 5);

	Control::setGlobalFocus(&rSex);
	EventEngine engine;
	engine.run(main);
	return 0;
}

