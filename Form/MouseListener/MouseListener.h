#pragma once


class Control;
//a struct that implements a listener
struct MouseListener
{
	//what heppens on mouse press
	virtual void mousePressed(Control* control, int x, int y, bool isleft) = 0;

};