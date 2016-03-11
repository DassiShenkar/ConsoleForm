#pragma once

#include <string>

using namespace std;

class RadioList
{
private:
	int x, y;
	string labels[];

public:
	RadioList();
	RadioList(int, int, string[]);
	~RadioList();
};


