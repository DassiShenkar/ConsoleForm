#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width), ttl(*new Label(10)), msg(*new Label(20))
{
	ttl.setText("");
	msg.setText("");
	msg.setBorder(BorderType::None);
	Button* ok = new Button(5);
	ok->setText("OK");
	ok->setBorder(BorderType::Single);
	ok->addListener(static_cast<MouseListener*>(this));
	ok->addListener(static_cast<KeyboardListener*>(this));

	Panel::addControl(ttl, width / 2, getStartY());
	Panel::addControl(msg, 1,  4);
	Panel::addControl(*ok, width / 2, 10);
	
}


Messagebox::~Messagebox()
{
	ttl.~Label();
	msg.~Label();
}

void Messagebox::mousePressed(Control* control, int x, int y)
{
	if (static_cast<Button*>(control)->getText() == "OK")
	{
		static_cast<Button*>(control)->~Button();
		this->~Messagebox();
	}
	else return;

}

void Messagebox::buttonKeyDown(KEY_EVENT_RECORD key)
{
	mousePressed(getGlobalInFocus(), getGlobalInFocus()->getStartX(), getGlobalInFocus()->getStartY());

}

void Messagebox::setTtl(string uttl) {
	this->ttl.setText("uttl");
}

void Messagebox::setMsg(string umsg) {
	this->msg.setText("umsg");
}