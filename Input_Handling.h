#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include "Point2D.h"
#include "Model.h"

#include <iostream>
#include <string>

using namespace std;

class Invalid_Input
{
public:
	Invalid_Input(string in_ptr): msg_ptr(in_ptr){ }
	const string msg_ptr;
private:
	Invalid_Input();
};

void get_movecommand(int &ID, Point2D &p)
{
	int in_ID;
	double in_x, in_y;
	if(!(cin >> in_ID >> in_x >> in_y))
	{
		//have to clear cin buffer to get rid of characters before the throw and the loop recirculates to the cin at the top of the loop
		cin.clear();
		throw Invalid_Input("Move command is in format: 'm' <int> <double> <double>");
	}
	//setting the Pass By Reference (PBR) variables if it passes checks
	p.x = in_x;
	p.y = in_y;
	ID = in_ID;
}

void get_movetocommand(char cmd, Model& model, int &ID1, int &ID2)
{
	int in_id1, in_id2;
	if(!(cin >> in_id1 >> in_id2))
	{
		cin.clear();
		throw Invalid_Input("Move to doctor or class is in format:\n'd' <int> <int>\n'c' <int> <int>");
	}
	//checking cmd code for doctors office or classroom commands
	switch(cmd)
	{
		case 'd':
			if(!(model.GetDoctorsOfficePtr(in_id1)))
			{
				cin.clear();
				throw Invalid_Input("Doctor office ID invalid");
			}
			break;
		case 'c':
			if(!(model.GetClassRoomPtr(in_id1)))
			{
				cin.clear();
				throw Invalid_Input("Classroom ID invalid");
			}
			break;
	}
	if(!(model.GetStudentPtr(in_id2)))
	{
		cin.clear();
		throw Invalid_Input("Student ID invalid");
	}
	//setting PBR variables if it not thrown
	ID1 = in_id1;
	ID2 = in_id2;
}

void get_stopcommand(Model& model, int& ID)
{
	int in_id;
	if(!(cin >> in_id))
	{
		cin.clear();
		throw Invalid_Input("Stop command is in format: 's' <int>");
	}
	if(!(model.GetStudentPtr(in_id)))
	{
		cin.clear();
		throw Invalid_Input("Student ID invalid");
	}
	//setting PBR variables if not thrown
	ID = in_id;
}

void get_gainstuffcommand(char cmd, Model& model, int& ID, unsigned int& amount)
{
	int in_id;
	unsigned int in_amount;
	if(!(cin >> in_id >> in_amount))
	{
		cin.clear();
		throw Invalid_Input("Buy vaccine or do class is in format:\n'v' <int> <unsigned int>\n'a' <int> <unsigned> <int>");
	}
	//checking cmd code for doctors office or classroom commands
	switch(cmd)
	{
		case 'v':
			if(!(model.GetDoctorsOfficePtr(in_id)))
			{
				cin.clear();
				throw Invalid_Input("Doctor office ID invalid");
			}
		case 'a':
			if(!(model.GetClassRoomPtr(in_id)))
			{
				cin.clear();
				throw Invalid_Input("Classroom ID invalid");
			}
	}
	//setting PBR variables if not thrown
	ID = in_id;
	amount = in_amount;
}

void get_newobject(Model& model, char & T, int &ID, Point2D& p)
{
	int in_id;
	char in_type;
	double x, y;
	if(!(cin >> in_type >> in_id >> x >> y))
	{
		cin.clear();
		throw Invalid_Input("New object comand is in format: 'n' <char> <int> <double> <double>");
	}
	else
	{
		//ensuring id will be 0-9 inclusive
		if (in_id > 9 || in_id < 0)
		{
			cin.clear();
			throw Invalid_Input("ID has to be between (and including) 0 and 9");
		}
		//checking if objects already in use/made
		switch(in_type)
		{
			case 'd':
				if (model.GetDoctorsOfficePtr(in_id))
				{
					cin.clear();
					throw Invalid_Input("Doctors Office ID is being used");
				}
				break;
			case 'c':
				if (model.GetClassRoomPtr(in_id))
				{
					cin.clear();
					throw Invalid_Input("Classroom ID is being used");
				}
				break;
			case 's':
				if (model.GetStudentPtr(in_id))
				{
					cin.clear();
					throw Invalid_Input("Student ID is being used");
				}
				break;
			case 'v':
				if (model.GetVirusPtr(in_id))
				{
					cin.clear();
					throw Invalid_Input("Virus ID is being used");
				}
				break;
			default:
				break;
		}
	}
	//setting PBR variables if not thrown
	T = in_type;
	ID = in_id;
	p.x = x;
	p.y = y;
}

#endif