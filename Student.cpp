#include "Student.h"

Student::Student():GameObject()
{
	assignments_to_buy = 0;
	vaccines_to_buy = 0;
	antibodies = 20;
	credits = 0;
	speed = 5;
	dollars = 0;
	cout << "Student default constructed." << endl;
}

Student::Student(char in_code):GameObject(in_code)
{
	assignments_to_buy = 0;
	vaccines_to_buy = 0;
	antibodies = 20;
	credits = 0;
	display_code = in_code;
	speed = 5;
	dollars = 0;
	state = STOPPED;
	cout << "Student constructed." << endl;
}

Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
:GameObject(in_loc, in_id, in_code)
{
	assignments_to_buy = 0;
	vaccines_to_buy = 0;
	id_num = in_id;
	location = in_loc;
	display_code = in_code;
	antibodies = 20;
	credits = 0;
	speed = in_speed;
	name = in_name;
	dollars = 0;
	cout << "Student constructed." << endl;

}

void Student::StartMoving(Point2D dest)
{
	SetupDestination(dest);
	state = MOVING;
	if(location.x == dest.x && location.y == dest.y)
	{
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}
	else if (IsInfected())
	{
		cout << display_code << id_num << ": I am infected. I may move but you cannot see me." << endl;
	}
	else
	{
		cout << display_code << id_num << ": On my way." << endl;
	}
}	


void Student::StartMovingToClass(ClassRoom* classr)
{
	current_class = classr;
	SetupDestination(classr -> GetLocation());
	state = MOVING_TO_CLASS;
	if(IsInfected())
	{
		cout << display_code << id_num << ": I am infected so I can't move to class..." << endl;
	}
	else if (location.x == destination.x && location.y == destination.y)
	{
		cout << display_code << id_num << ": I am already at the Classroom!" << endl;
	}
	else
	{
		cout << display_code << id_num << ": on my way to class " << classr->GetId() << endl;
	}
}

void Student::StartMovingToDoctor(DoctorsOffice* office)
{
	current_office = office;
	SetupDestination(office -> GetLocation());
	state = MOVING_TO_DOCTOR;
	if (IsInfected())
	{
		cout << display_code << id_num << ": I am infected so I should have gone to the doctor's..." << endl;
	}
	else if (location.x == destination.x && location.y == destination.y)
	{
		cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
	}
	else
	{
		cout << display_code << id_num << ": On my way to the doctor's " << office -> GetId() << endl;
	}
}

void Student::StartLearning(unsigned int num_assignments)
{
	state = STUDYING_IN_CLASS; 
	if (IsInfected())
	{
		cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
	}
	else if ((current_class->GetLocation()).x != location.x || (current_class->GetLocation()).y != location.y)
	{
		cout << display_code << id_num << ": I can only learn in a ClassRoom!" << endl;
	}
	else if (dollars < (current_class->GetDollarCost(num_assignments)))
	{
		cout << display_code << id_num << ": Not enough money for school" << endl;
	}
	else if ((current_class->GetNumAssignmentsRemaining()) == 0)
	{
		cout << display_code << id_num << ": Cannot learn! This Class has no more assignments!" << endl;
	}
	else if ((current_class->GetLocation()).x == location.x && (current_class->GetLocation()).y == location.y)//can probably make this just else not else if
	{
		cout << display_code << id_num << ": Started to learn at the ClassRoom " << current_class->GetId() << 
		 " with " << num_assignments << "assignments!" << endl;
		 assignments_to_buy = min(num_assignments,current_class->GetNumAssignmentsRemaining());
		 credits += assignments_to_buy;
	}
}	

void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
{
	state = RECOVERING_ANTIBODIES;
	if (dollars < (current_office->GetDollarCost(num_vaccines)))
	{
		cout << display_code << id_num << ": Not enough money to recover antibodies." << endl;
	}
	else if ((current_office->GetNumVaccineRemaining()) == 0)
	{
		cout << display_code << id_num << ": Cannot recover! No vaccine remaining in this Doctor's Office" << endl;
	}
	else if (location.x != (current_office->GetLocation()).x ||location.y != (current_office->GetLocation()).y)
	{
		cout << display_code << id_num << ": I can only recover antibodies at a Doctor's Office!" << endl;
	}
	else if (location.x == (current_office->GetLocation()).x && location.y == (current_office->GetLocation()).y)//can probably make this just else not else if
	{
		cout << display_code << id_num << ": Started recovering " << num_vaccines << " vaccines at Doctor's Office" << 
		current_office->GetId() << endl;
		vaccines_to_buy = min(num_vaccines, current_office->GetNumVaccineRemaining());
		current_office->DistributeVaccine(vaccines_to_buy);
		antibodies += (5*vaccines_to_buy);
	}
}

void Student::Stop()
{
	state = STOPPED;
	cout << display_code << id_num << ": Stopping...";
}

bool Student::IsInfected()
{
	if (antibodies == 0)
		return true;
	else
		return false;
}

bool Student::ShouldBeVisible()
{
	if (IsInfected())
		return false;
	else
		return true;
}

void Student::ShowStatus()
{
	cout << name << " status:" << endl;
	GameObject::ShowStatus();
	//Refer to How Student Objects Behave
	switch (state)
	{
		case 0:
			cout << "stopped" << endl;
			break;
		case 1: //destination is type Point2D but instructions want it to be in vector format?
			cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << "." << endl;
			break;	
		case 3:
			cout << "inside Doctor's Office " << current_office->GetId() << endl;
			break;
		case 4:
			cout << "inside Classroom " << current_class->GetId() << endl;
			break;
		case 5:
			cout << "heading to Doctor's Office " << current_office->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
			break;
		case 6:
			cout << "heading to Classroom " << current_class->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
			break;
		case 7:
			cout << "studying in Classroom " << current_class->GetId() << endl;
			break;
		case 8:
			cout << "recovering antibodies in Doctor's Office " << current_office->GetId() << endl;
			break;
		default:
			break;
	}
	cout << "Antibodies: " << antibodies << endl;
	cout << "Dollars: " << dollars << endl;
	cout << "Credits: " << credits << endl;
}

bool Student::Update()
{
	//Refer to How Student Objects Behave
	if (IsInfected())
	{
		state = INFECTED;
		return false; 
	}
	switch (state)
	{
		case 0:
			return false;
			break;
		case 1:
			UpdateLocation();
			if (location.x == destination.x && location.y == destination.y)
			{
				state = STOPPED;
				return true;
			}
			else
			{
				state = MOVING;
				return false;
			}
			break;
		case 3:
			return false;
			break;
		case 4:
			return false;
			break;
		case 5:
			UpdateLocation();
			if(location.x == destination.x && location.y == destination.y)
			{
				state = AT_DOCTORS;
				return true;
			}
			else
			{
				state = MOVING_TO_DOCTOR;
				return false;
			}
			break;
		case 6:
			UpdateLocation();
			if (location.x == destination.x && location.y == destination.y)
			{
				state = IN_CLASS;
				return true;
			}
			else
			{
				state = MOVING;
				return false;
			}
			break;
		case 7:
			antibodies -= current_class->GetAntibodyCost(assignments_to_buy);
			dollars -= current_class->GetDollarCost(assignments_to_buy);
			credits += current_class->TrainStudents(assignments_to_buy);
			cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)! **" << endl;
			cout << "** " << name << " gained " << current_class->TrainStudents(assignments_to_buy) << " credit(s)! **" << endl;
			state = IN_CLASS;
			return true;
			break;
		case 8:
			//antibodies += 5*vaccine_to_buy is in StartRecoveringAntibodies member function
			// StartRecoveringAntibodies(vaccines_to_buy); (already call this in GameCommand later so no need here)
			dollars -= current_office->GetDollarCost(vaccines_to_buy);
			cout << "** " << name << " recovered " <<  5*vaccines_to_buy << " antibodies! **" << endl;
			cout << "** " << name << " bought " << vaccines_to_buy << " vaccine(s)! **" << endl;
			state = AT_DOCTORS;
			return true;
			break;
		default:
			return false;
			break;
	}
}

bool Student::UpdateLocation()
{
	//Refer to How the Student Moves
	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
	{	
		location.x = destination.x;
		location.y = destination.y;
		cout << "arrived" << endl;
		return true;
	}
	else
	{
		location.x += delta.x;
		location.y += delta.y;
		cout << "moved" << endl;
		dollars += GetRandomAmountOfDollars();
		antibodies --;
		return false;
	}

}

void Student::SetupDestination(Point2D dest)
{
	state = MOVING;
	destination.x = dest.x;
	destination.y = dest.y;
	delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
	//Refer to How the Student Moves
}

static double GetRandomAmountOfDollars()
{
	srand(time(NULL));
	double min = 0.0;
	double max = 2.0;
	double randNum = (double)rand() / RAND_MAX;
	return (min + randNum * (max - min));
}

//Getter for name: added for GameCommand.cpp
	//this is because name is private, so needs a getter or friend, but i chose getter
string Student::getName() const
{
	return name;
}
//extra questions:
//How to get exact classroom id: use current_class->GetId()



//below is attempt to get virus to latch onto student**
// Point2D Student::getDestination() const
// {
// 	return destination;
// }

// Vector2D Student::getDelta() const
// {
// 	return delta;
// }