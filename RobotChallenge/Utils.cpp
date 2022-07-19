#include "Utils.h"

#include <sstream>

bool Utils::IsCommandValid(string in_command, string* out_command)
{
    vector<string> commandElements = SplitString(in_command, ' ');

    if (in_command == g_move || in_command == g_left || in_command == g_right || in_command == g_report)
    {
        if (commandElements.size() == 1)
        {
            *out_command = in_command;
            return true;
        }
    }
    else if (in_command.starts_with("PLACE "))
    {
        if (commandElements.size() > 1)
        {
            *out_command = g_place;
            return true;
        }
    }
    return false;
}

bool Utils::GetPlaceParams(string placeCommand, int* x, int* y, string *f)
{
    vector<string> commandElements = SplitString(placeCommand, ' ');
    vector<string> placeParams = SplitString(commandElements[1], ',');

    if (placeParams.size() == 3)
    {
        *x = stoi(placeParams[0]);
        *y = stoi(placeParams[1]);
        *f = GetFaceInput(placeParams[2]);

        if (!((*x >= TABLEMIN && *x <= TABLEMAX) && (*y >= TABLEMIN && *y <= TABLEMAX) && (*f != "")))
        {
            *x = -1;
            *y = -1;
            *f = "";
            return false;
        }
        else
        {
            //cout << "Params: " << *x << ", " << *y << ", " << *f;
            return true;
        }
    }
    
    return false;
}

vector<string> Utils::SplitString(string rawString, char delim)
{
    string elements;
    vector<string> stringElements;
    stringstream S(rawString);

    while (getline(S, elements, delim))
    {
        stringElements.push_back(elements);
    }
    return stringElements;
}

string Utils::GetFaceInput(string in_face)
{
    transform(in_face.begin(), in_face.end(), in_face.begin(), ::toupper);  //uppercase
    if (in_face == g_north || in_face == g_south || in_face == g_east || in_face == g_west)
    {
        return in_face;
    }
    return "";
}
