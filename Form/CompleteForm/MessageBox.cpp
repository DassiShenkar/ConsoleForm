#include "MessageBox.h"



MessageBox::MessageBox(int height, int width) : Panel2(height,width)
{
	addControl(Label2(0), 0, 0);
	addControl(Label2(0), 0, 4);
	addControl(Button2(), 5, 12);
}


MessageBox::~MessageBox()
{
}

void MessageBox::setTtl(string ttl) {
	vector<Control*>::iterator it;
	//Control *ctrl = items.begin();
	it = items.begin();
	Label2* tempttl = new Label2(0);
	tempttl->setText(ttl);
	(*it) = tempttl;
}

void MessageBox::setMsg(string msg) {
	int i = 0;
	vector<Control*>::iterator it;
	Label2* tempmsg = new Label2(0);
	tempmsg->setText(msg);
	for ( it = items.begin(); it != items.end(); it++ , i++)
	{
		if (i == 1)
		{
			(*it) = tempmsg;
		}
		//(*it)->setStartPosition({ position.X + (*it)->getStartPosition().X, position.Y + (*it)->getStartPosition().Y });
	}

}