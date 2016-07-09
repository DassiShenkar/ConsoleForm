#include <string>
#include "EventEngine.h"
#include "TextBox.h"
#include "Label.h"
#include "Button.h"
#include "Panel.h"
#include "NumericBox.h"
#include "RadioList.h"
#include "CheckList.h"
#include "MouseListener.h"
#include "MessageBox.h"
using namespace std;

struct MyListener : public MouseListener2
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Button2 &b, int x, int y, bool isLeft)
	{
		_c.setForeground(ForegroundColor::Red);
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
	Label2 lName(20);
	lName.setText("Name: ");

	Label2 lAddress(20);
	lAddress.setText("Address:");
	Label2 lCountry(20);
	lCountry.setText("Counrty:");
	Label2 lSex(20);
	lSex.setText("Sex:");
	Label2 lInterests(20);
	lInterests.setText("Interests:");
	Label2 lAge(20);
	lAge.setText("Age:");

	/*TextBox2 tName(20);
	tName.setText("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	//TextBox2 tAddress(25);
	tAddress.setText("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	*/
	//ComboBox2 cCountry(20, { "Israel", "Great Britain", "United States" });
	//cCountry.setSelectedIndex(1);
	//cCountry.setBorder(BorderType::Single);
	RadioList2 rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList2 clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox2 nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
	//MyListener listener(tAddress);
	Button2 bSubmit(10);
	bSubmit.setText("Submit");
	//bSubmit.addListener(listener);
	bSubmit.setBorder(BorderType::Double);
	Panel2 main;
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	//main.addControl(tName, 25, 2);
	//main.addControl(tAddress, 25, 5);
	//main.addControl(cCountry, 25, 8);
	//main.addControl(rSex, 25, 11);
	//main.addControl(clInterests, 25, 15);

	//main.addControl(nAge, 25, 20);

	main.addControl(bSubmit, 1, 22);
	Control::setFocus(&rSex);
	EventEngine engine;
	engine.run(main);
	return 0;
}

