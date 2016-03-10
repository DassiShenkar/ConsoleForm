#pragma once

#include <string>

using namespace std;

class RadioInput
{
private:
	int x, y;
	string labels[];

public:
	RadioInput();
	RadioInput(int, int, string[]);
	~RadioInput();
};

