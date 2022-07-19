#pragma once

#include "stdfax.h";

class Robot
{
public:
	enum Face {
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	void Place(int x, int y, string face);
	void Move();
	void Left();
	void Right();
	void Report();
	bool IsOnTable();

#ifndef UNIT_TEST
private:
#endif

	int x_pos = -1;
	int y_pos = -1;
	string f_pos = "";
	int f_val = NORTH;
};

