#pragma once
#include "MouseListener.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class Messagebox : public Panel, public MouseListener, public KeyboardListener
{				
private:
	Label ttl;
	Label msg;
public:
	Messagebox(int height, int width);

	~Messagebox();

	virtual void mousePressed(Control* control, int x, int y);

	virtual void buttonKeyDown(KEY_EVENT_RECORD key);

	void setTtl(string ttl);

	void setMsg(string msg);

};

