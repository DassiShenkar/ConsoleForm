#include "Messagebox.h"

Messagebox::Messagebox(int height, int width) : Panel(height, width), ttl(*new Label(10)), msg(*new Label(20))
{
	deleted = false;
	ttl.setText("");
	msg.setText("");
	msg.setBorder(BorderType::None);
	Button* tok = new Button(5);
	ok = tok;
	ok->setText("OK");
	ok->setBorder(BorderType::Single);
	ok->addListener(static_cast<MouseListener*>(this));
	ok->addListener(static_cast<KeyboardListener*>(this));

	Panel::addControl(ttl, width / 3, getStartY() + 1 );
	Panel::addControl(msg, 1,  3);
	Panel::addControl(*ok, width / 2, 8);
	
}


Messagebox::~Messagebox()
{
	
}



void Messagebox::mousePressed(Control* control, int x, int y,bool isLeft)
{
	if (static_cast<Button*>(control)->getText() == "OK")
	{
		this->setBorder(BorderType::None);
		ttl.setBorder(BorderType::None);
		ttl.setText("");
		//ttl.~Label();
		msg.setText("");
		//msg.~Label();
		static_cast<Button*>(control)->setText("");
		static_cast<Button*>(control)->setBorder(BorderType::None);
		//delete &ttl;
		//delete &msg;
		//this->~Messagebox();
		//free(this);
		//this->~Messagebox();
		//static_cast<Button*>(control)->~Button();
		//control->~Control();
		//this->items.~vector();

	}
	else return;

}

void Messagebox::buttonKeyDown(KEY_EVENT_RECORD key)
{
	mousePressed(getGlobalInFocus(), getGlobalInFocus()->getStartX(), getGlobalInFocus()->getStartY(), true);

}

void Messagebox::setTtl(string uttl) {
	this->ttl.setText(uttl);
}

void Messagebox::setMsg(string umsg) {
	this->msg.setText(umsg);
}

bool Messagebox::isDel()
{
	return deleted;
}

