#include "Robot.h"

void Robot::Place(int x, int y, string face)
{
	x_pos = x;
	y_pos = y;
	f_pos = face;

	if (face == g_north) f_val = NORTH;
	else if (face == g_east) f_val = EAST;
	else if (face == g_south) f_val = SOUTH;
	else if (face == g_west) f_val = WEST;
}

void Robot::Move()
{
	switch (f_val)
	{
		case NORTH:
			if (y_pos+1 <= TABLEMAX) y_pos++;
			break;
		case EAST:
			if (x_pos+1 <= TABLEMAX) x_pos++;
			break;
		case SOUTH:
			if (y_pos-1 >= TABLEMIN) y_pos--;
			break;
		case WEST:
			if (x_pos-1 >= TABLEMIN) x_pos--;
			break;
		default:
			break;
	}
}

void Robot::Left()
{
	if (f_val-1 < NORTH) f_val = WEST;
	else f_val--;
}

void Robot::Right()
{
	if (f_val+1 > WEST) f_val = NORTH;
	else f_val++;
}

void Robot::Report()
{
	switch (f_val)
	{
		case NORTH:
			f_pos = g_north;
			break;
		case EAST:
			f_pos = g_east;
			break;
		case SOUTH:
			f_pos = g_south;
			break;
		case WEST:
			f_pos = g_west;
			break;
		default:
			f_pos = "";
			break;
	}
	cout << "Output: " << x_pos << ", " << y_pos << ", " << f_pos << endl;
}

bool Robot::IsOnTable()
{
	if (x_pos < TABLEMIN || x_pos > TABLEMAX)
		return false;
	else if (y_pos < TABLEMIN || y_pos > TABLEMAX)
		return false;
	else
	{
		if (!(f_pos == g_north || f_pos == g_south || f_pos == g_east || f_pos == g_west))
			return false;
	}
	return true;
}
