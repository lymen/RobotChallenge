#include "pch.h"

#define UNIT_TEST
#include "../RobotChallenge/stdfax.h"
#include "../RobotChallenge/Utils.h"
#include "../RobotChallenge/Utils.cpp"
#include "../RobotChallenge/Robot.h"
#include "../RobotChallenge/Robot.cpp"

//bool IsCommandValid(string in_command, string* out_command);
TEST(TestIsCommandValid, test_IsCommandValid) {
	Utils testUtils;
	struct TestData {
		string	in_command;
		string	out_command;
		bool	retValue;
	};

	TestData td[] = {
		{g_move,			g_move,		true},
		{g_left,			g_left,		true},
		{g_right,			g_right,	true},
		{g_report,			g_report,	true},
		{"PLACE 0,0,NORTH",	g_place,	true},
		{"INVALID COMMAND",	"",			false},
		{g_place,			"",			false},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		string out_command = "";
		bool retVal = testUtils.IsCommandValid(td[i].in_command, &out_command);
		EXPECT_EQ(out_command, td[i].out_command);
		EXPECT_EQ(retVal, td[i].retValue);
	}
}

// bool GetPlaceParams(string placeCommand, int* x, int* y, string *f);
TEST(TestGetPlaceParams, test_GetPlaceParams) {
	Utils testUtils;
	struct TestData {
		string	in_placeCommand;
		int		out_x;
		int		out_y;
		string	out_f;
		bool	retValue;
	};

	TestData td[] = {
		{"PLACE 0,0,NORTH",		0,	0,	g_north,	true},
		{"PLACE 0,0,EAST",		0,	0,	g_east,		true},
		{"PLACE 0,0,SOUTH",		0,	0,	g_south,	true},
		{"PLACE 0,0,WEST",		0,	0,	g_west,		true},
		{"PLACE 0,0,FACE",		-1,	-1,	"",			false},
		{"PLACE 4,4,NORTH",		4,	4,	g_north,	true},
		{"PLACE 4,4,EAST",		4,	4,	g_east,		true},
		{"PLACE 4,4,SOUTH",		4,	4,	g_south,	true},
		{"PLACE 4,4,WEST",		4,	4,	g_west,		true},
		{"PLACE 4,4,FACE",		-1,	-1,	"",			false},
		{"PLACE -1,-1,NORTH",	-1,	-1,	"",			false},
		{"PLACE -1,-1,EAST",	-1,	-1,	"",			false},
		{"PLACE -1,-1,SOUTH",	-1,	-1,	"",			false},
		{"PLACE -1,-1,WEST",	-1,	-1,	"",			false},
		{"PLACE -1,-1,FACE",	-1,	-1,	"",			false},
		{"PLACE 5,5,NORTH",		-1,	-1,	"",			false},
		{"PLACE 5,5,EAST",		-1,	-1,	"",			false},
		{"PLACE 5,5,SOUTH",		-1,	-1,	"",			false},
		{"PLACE 5,5,WEST",		-1,	-1,	"",			false},
		{"PLACE 5,5,FACE",		-1,	-1,	"",			false},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		int x, y;
		string f;
		bool retVal = testUtils.GetPlaceParams(td[i].in_placeCommand, &x, &y, &f);
		EXPECT_EQ(x, td[i].out_x);
		EXPECT_EQ(y, td[i].out_y);
		EXPECT_EQ(f, td[i].out_f);
		EXPECT_EQ(retVal, td[i].retValue);
	}
}

//string GetFaceInput(string in_face);
TEST(TestGetFaceInput, test_GetFaceInput) {
	Utils testUtils;
	struct TestData {
		string	in_face;
		string retValue;
	};

	TestData td[] = {
		{g_north,	g_north},
		{g_east,	g_east},
		{g_south,	g_south},
		{g_west,	g_west},
		{"FACE",	""},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		string retVal = testUtils.GetFaceInput(td[i].in_face);
		EXPECT_EQ(retVal, td[i].retValue);
	}
}

//void Place(int x, int y, string face);
TEST(TestPlace, test_Place) {
	Robot testRobot;
	struct TestData {
		int	in_x;
		int in_y;
		string in_f;
		int x_pos;
		int y_pos;
		string f_pos;
		int f_val;
	};

	TestData td[] = {
		{0,	0, g_north, 0, 0, g_north, Robot::NORTH},
		{0,	0, g_east, 0, 0, g_east, Robot::EAST},
		{0,	0, g_south, 0, 0, g_south, Robot::SOUTH},
		{0,	0, g_west, 0, 0, g_west, Robot::WEST},
		{4,	4, g_north, 4, 4, g_north, Robot::NORTH},
		{4,	4, g_east, 4, 4, g_east, Robot::EAST},
		{4,	4, g_south, 4, 4, g_south, Robot::SOUTH},
		{4,	4, g_west, 4, 4, g_west, Robot::WEST},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.Place(td[i].in_x, td[i].in_y, td[i].in_f);
		EXPECT_EQ(testRobot.x_pos, td[i].x_pos);
		EXPECT_EQ(testRobot.y_pos, td[i].y_pos);
		EXPECT_EQ(testRobot.f_pos, td[i].f_pos);
		EXPECT_EQ(testRobot.f_val, td[i].f_val);
	}
}

//void Robot::Move()
TEST(TestMove, test_Move) {
	Robot testRobot;
	struct TestData {
		int	in_x;
		int in_y;
		string in_f;
		int in_fval;
		int x_pos;
		int y_pos;
		string f_pos;
		int f_val;
	};

	TestData td[] = {
		{0,	0, g_north,	Robot::NORTH,	0, 1, g_north,	Robot::NORTH},
		{0,	0, g_east,	Robot::EAST,	1, 0, g_east,	Robot::EAST},
		{0,	0, g_south,	Robot::SOUTH,	0, 0, g_south,	Robot::SOUTH},
		{0,	0, g_west,	Robot::WEST,	0, 0, g_west,	Robot::WEST},
		{4,	4, g_north,	Robot::NORTH,	4, 4, g_north,	Robot::NORTH},
		{4,	4, g_east,	Robot::EAST,	4, 4, g_east,	Robot::EAST},
		{4,	4, g_south,	Robot::SOUTH,	4, 3, g_south,	Robot::SOUTH},
		{4,	4, g_west,	Robot::WEST,	3, 4, g_west,	Robot::WEST},
		{3,	3, g_north,	Robot::NORTH,	3, 4, g_north,	Robot::NORTH},
		{3,	3, g_east,	Robot::EAST,	4, 3, g_east,	Robot::EAST},
		{3,	3, g_south,	Robot::SOUTH,	3, 2, g_south,	Robot::SOUTH},
		{3,	3, g_west,	Robot::WEST,	2, 3, g_west,	Robot::WEST},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.x_pos = td[i].in_x;
		testRobot.y_pos = td[i].in_y;
		testRobot.f_pos = td[i].in_f;
		testRobot.f_val = td[i].in_fval;
		testRobot.Move();
		EXPECT_EQ(testRobot.x_pos, td[i].x_pos);
		EXPECT_EQ(testRobot.y_pos, td[i].y_pos);
		EXPECT_EQ(testRobot.f_pos, td[i].f_pos);
		EXPECT_EQ(testRobot.f_val, td[i].f_val);
	}
}

//void Robot::Left()
TEST(TestLeft, test_Left) {
	Robot testRobot;
	struct TestData {
		int in_fval;
		int f_val;
	};

	TestData td[] = {
		{Robot::NORTH,	Robot::WEST},
		{Robot::EAST,	Robot::NORTH},
		{Robot::SOUTH,	Robot::EAST},
		{Robot::WEST,	Robot::SOUTH},
		{Robot::NORTH,	Robot::WEST},
		{Robot::EAST,	Robot::NORTH},
		{Robot::SOUTH,	Robot::EAST},
		{Robot::WEST,	Robot::SOUTH},
		{Robot::NORTH,	Robot::WEST},
		{Robot::EAST,	Robot::NORTH},
		{Robot::SOUTH,	Robot::EAST},
		{Robot::WEST,	Robot::SOUTH},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.f_val = td[i].in_fval;
		testRobot.Left();
		EXPECT_EQ(testRobot.f_val, td[i].f_val);
	}
}

//void Robot::Right()
TEST(TestRight, test_Right) {
	Robot testRobot;
	struct TestData {
		int in_fval;
		int f_val;
	};

	TestData td[] = {
		{Robot::NORTH,	Robot::EAST},
		{Robot::EAST,	Robot::SOUTH},
		{Robot::SOUTH,	Robot::WEST},
		{Robot::WEST,	Robot::NORTH},
		{Robot::NORTH,	Robot::EAST},
		{Robot::EAST,	Robot::SOUTH},
		{Robot::SOUTH,	Robot::WEST},
		{Robot::WEST,	Robot::NORTH},
		{Robot::NORTH,	Robot::EAST},
		{Robot::EAST,	Robot::SOUTH},
		{Robot::SOUTH,	Robot::WEST},
		{Robot::WEST,	Robot::NORTH},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.f_val = td[i].in_fval;
		testRobot.Right();
		EXPECT_EQ(testRobot.f_val, td[i].f_val);
	}
}

//void Robot::Report()
TEST(TestReport, test_Report) {
	Robot testRobot;
	struct TestData {
		int	in_x;
		int in_y;
		int in_fval;
		int x_pos;
		int y_pos;
		string f_pos;
		int f_val;
	};

	TestData td[] = {
		{0,	0, Robot::NORTH,	0, 0, g_north,	Robot::NORTH},
		{0,	0, Robot::EAST,		0, 0, g_east,	Robot::EAST},
		{0,	0, Robot::SOUTH,	0, 0, g_south,	Robot::SOUTH},
		{0,	0, Robot::WEST,		0, 0, g_west,	Robot::WEST},
		{4,	4, Robot::NORTH,	4, 4, g_north,	Robot::NORTH},
		{4,	4, Robot::EAST,		4, 4, g_east,	Robot::EAST},
		{4,	4, Robot::SOUTH,	4, 4, g_south,	Robot::SOUTH},
		{4,	4, Robot::WEST,		4, 4, g_west,	Robot::WEST},
		{3,	3, Robot::NORTH,	3, 3, g_north,	Robot::NORTH},
		{3,	3, Robot::EAST,		3, 3, g_east,	Robot::EAST},
		{3,	3, Robot::SOUTH,	3, 3, g_south,	Robot::SOUTH},
		{3,	3, Robot::WEST,		3, 3, g_west,	Robot::WEST},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.x_pos = td[i].in_x;
		testRobot.y_pos = td[i].in_y;
		testRobot.f_val = td[i].in_fval;
		testRobot.Report();
		EXPECT_EQ(testRobot.x_pos, td[i].x_pos);
		EXPECT_EQ(testRobot.y_pos, td[i].y_pos);
		EXPECT_EQ(testRobot.f_pos, td[i].f_pos);
		EXPECT_EQ(testRobot.f_val, td[i].f_val);
	}
}

//void Robot::IsOnTable()
TEST(TestIsOnTable, test_IsOnTable) {
	Robot testRobot;
	struct TestData {
		int	in_x;
		int in_y;
		string in_f;
		bool ret_value;
	};

	TestData td[] = {
		{0,		0, g_north,		true},
		{0,		0, g_east,		true},
		{0,		0, g_south,		true},
		{0,		0, g_west,		true},
		{0,		0, "FACE",		false},
		{4,		4, g_north,		true},
		{4,		4, g_east,		true},
		{4,		4, g_south,		true},
		{4,		4, g_west,		true},
		{4,		4, "FACE",		false},
		{-1,	-1, g_north,	false},
		{-1,	-1, g_east,		false},
		{-1,	-1, g_south,	false},
		{-1,	-1, g_west,		false},
		{-1,	-1, "FACE",		false},
		{5,		5, g_north,		false},
		{5,		5, g_east,		false},
		{5,		5, g_south,		false},
		{5,		5, g_west,		false},
		{5,		5, "FACE",		false},
	};

	for (int i = 0; i < sizeof(td) / sizeof(td[0]); i++) {
		testRobot.x_pos = td[i].in_x;
		testRobot.y_pos = td[i].in_y;
		testRobot.f_pos = td[i].in_f;
		bool retVal = testRobot.IsOnTable();
		EXPECT_EQ(retVal, td[i].ret_value);
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
