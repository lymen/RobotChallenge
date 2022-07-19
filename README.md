# RobotChallenge

### Prerequisites
These projects are developed using a Visual Studio 2022 Solution.

C++20 is used.

Test Adaptor for Google Test is used for automated testing. Make sure this is included on your Visual Studio Environment

### File System
* RobotChallenge.sln - Visual Studio Solution
 
+ RobotChallenge/
   
    ```
    contains the project that implements the Robot Challenge
    ```
+ TestRobotChallenge/
   
    ```
    contains the project for automated testing
    ```
     
### Project / Module List
* RobotChallenge/RobotChallenge.cpp
	Contains the main implementation of the project.
* RobotChallenge/Robot
    + Module that hold the robot attributes and actions/commands
* RobotChallenge/Utils
    + Contains the necessary functions and utilities needed but not related to the Robot
* TestRobotChallenge/test.cpp
    + Contains the implementation of the automated testing
 
### Setup
To Run the RobotChallenge program:

    1. Install Visual Studio 2022
      - Include Desktop development with C++
      - Include Test Adapter for Google Test
    2. Open **RobotChallenge.sln**
    3. Press F5 to run the program or click Local Windows Debugger
    
To run the Tests:

    1. Right click on the TestRobotChallenge Project in the Solutions Explorer window
    2. Build
    3. Click Test Menu -> Run All Tests

### Notes
Build error may occur for some unrecognized functions/syntax:

	1. Go to Project Properties (both main and test projects)
	2. Under Configuration Properties, select C/C++ -> Language
	3. Select ISO C++20 Standard (/std:c++20) for C++ Language Standard