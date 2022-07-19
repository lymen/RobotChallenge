#include <iostream>

#include "Robot.h"
#include "Utils.h"

int main()
{
    cout << "Robot Challenge\n";
    cout << "- commands MOVE, LEFT, RIGHT, REPORT are not case sensitive\n";
    cout << "- accepted PLACE command format is only 'PLACE x,y,f' but are not case sensitive\n";
    cout << "- EXIT command to close\n\n";

    Robot toyRobot = Robot();
    Utils robotUtils = Utils();
    
    while (1)
    {
        cout << "Input Command: ";

        int x, y;
        string f;
        string in_command, currentCommand;

        getline(cin, in_command);
        transform(in_command.begin(), in_command.end(), in_command.begin(), ::toupper);  //uppercase

        if (in_command == g_exit)
        {
            break;
        }

        if (robotUtils.IsCommandValid(in_command, &currentCommand) == false)
        {
            //Continue motherloop
            cout << "INVALID COMMAND\n";
            continue;
        }

        if (currentCommand == g_place)
        {
            if (robotUtils.GetPlaceParams(in_command, &x, &y, &f))
            {
                toyRobot.Place(x, y, f);
            }
            else
            {
                cout << "INVALID COMMAND (Parameters)\n";
                continue;
            }
        }
        else
        {
            if (toyRobot.IsOnTable())
            {
                if (currentCommand == g_move)
                {
                    toyRobot.Move();
                }
                else if (currentCommand == g_left)
                {
                    toyRobot.Left();
                }
                else if (currentCommand == g_right)
                {
                    toyRobot.Right();
                }
                else if (currentCommand == g_report)
                {
                    toyRobot.Report();
                }
            }
        }
    }
}