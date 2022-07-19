#pragma once

#include "stdfax.h";

class Utils
{
public:
	bool IsCommandValid(string in_command, string* out_command);
	bool GetPlaceParams(string placeCommand, int* x, int* y, string *f);
	vector<string> SplitString(string rawString, char delim);
	string GetFaceInput(string in_face);
};

