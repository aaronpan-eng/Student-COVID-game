#include <iostream>

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Student.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Input_Handling.h"

using namespace std;

int main()
{
	Model M;
	View V;
	Point2D p1;
	int ID, ID1, ID2;
	unsigned int vaccine_amount, assignment_amount;
	char cmd;
	char TYPE;//for the new object stuff

	bool loop = true;

	M.ShowStatus();
	M.Display(V);

	while (loop == true)
	{	
		cout << "Enter game command:" << endl;
		try
		{
			cin >> cmd;
			cmd = tolower(cmd); //lowercase of input

			switch(cmd)
			{
				case 'm':
					get_movecommand(ID, p1);//input handling func
					DoMoveCommand(M, ID, p1);
					break;
				case 'd':
					get_movetocommand(cmd, M, ID1, ID2);//input handling func
					DoMoveToDoctorCommand(M, ID1, ID2);
					break;
				case 'c':
					get_movetocommand(cmd, M, ID1, ID2);//input handling func
					DoMoveToClassCommand(M, ID1, ID2);
					break;
				case 's':
					get_stopcommand(M, ID);//input handling func
					DoStopCommand(M, ID);
					break;
				case 'v':
					get_gainstuffcommand(cmd, M, ID, vaccine_amount);//input handling func
					DoRecoverInOfficeCommand(M, ID, vaccine_amount);
					break;
				case 'a':
					get_gainstuffcommand(cmd, M, ID, assignment_amount);//input handling func
					DoLearningCommand(M, ID, assignment_amount);
					break;
				case 'g':
					DoGoCommand(M, V);
					break;
				case 'r':
					DoRunCommand(M, V);
					break;
				case 'q':
					loop = false;
					cout << "Quitting Program!" << endl;
					break;
				case 'n':
					get_newobject(M, TYPE, ID, p1);
					M.NewCommand(TYPE, ID, p1);
					M.ShowStatus();
					break;
				default:
					cin.clear();
					throw Invalid_Input("Invalid command");
					break;		
			}
		}
		catch(Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
	}

}