


#include <iostream>
#include <wchar.h>
#include <string.h>

#include "..\CompleteForm\TextBox.h"
#include "..\CompleteForm\Label.h"
#include "..\CompleteForm\Button.h"
#include "..\CompleteForm\Panel.h"
#include "..\CompleteForm\NumericBox.h"
#include "..\CompleteForm\ComboBox.h"
#include "..\CompleteForm\RadioList.h"
#include "..\CompleteForm\CheckList.h"
#include "..\CompleteForm\MouseListener.h"
#include "..\CompleteForm\EventEngine.h"
#include "..\CompleteForm\Widget.h"
#include "..\CompleteForm\ConsoleHandler.h"

using namespace std;


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
	/*TextBox tName(20);
	tName.setText("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	TextBox tAddress(25);
	tAddress.setText("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	*/ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	//cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	//clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setCurrentValue(23);
	nAge.setBorder(BorderType::Single);
	//MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.setText("Submit");
	//bSubmit.addListener(listener);
	bSubmit.setBorder(BorderType::Double);
	Panel main(60, 40);
	main.addControl(&lName, { 1, 2 });
	main.addControl(&lAddress, { 1, 5 });
	main.addControl(&lCountry, { 1, 8 });
	main.addControl(&lSex, { 1, 11 });
	main.addControl(&lInterests, { 1, 15 });
	main.addControl(&lAge, { 1, 20 });
	//main.addControl(&tName, { 25, 2 });
	//main.addControl(&tAddress, { 25, 5 });
	main.addControl(&cCountry, { 25, 8 });
	main.addControl(&rSex, { 25, 11 });
	main.addControl(&clInterests, { 25, 15 });
	main.addControl(&nAge, { 25, 20 });

	main.addControl(&bSubmit, { 1, 22 });
	main.printWidget();
	ConsoleHandler* console = ConsoleHandler::getInstance();
	console->attach(&main);
	console->start();

	return 0;
}