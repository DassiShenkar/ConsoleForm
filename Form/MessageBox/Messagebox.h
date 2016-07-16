#pragma once
#include "../MouseListener/MouseListener.h"
#include "../KeyboardListener/KeyboardListener.h"

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class Messagebox : public Panel, public MouseListener, public KeyboardListener
{				
private:
	bool deleted;
	Label ttl;
	Label msg;
	Button *ok;
public:
	Messagebox(int height, int width);

	~Messagebox();

	virtual void mousePressed(Control* control, int x, int y, bool isLeft);

	virtual void buttonKeyDown(KEY_EVENT_RECORD key);

	void setTitle(string ttl);

	void setText(string msg);

	bool isDel();

};

