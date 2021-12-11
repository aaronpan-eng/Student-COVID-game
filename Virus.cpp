#include "Virus.h"

Virus::Virus(string in_name, double in_virulence, double in_resistance, double in_energy,
bool in_variant, int in_id, Point2D in_loc):GameObject('V', in_id, in_loc)
{
	name = in_name;
	virulence = in_virulence;
	resistance = in_resistance;
	energy = in_energy;
	variant = in_variant;
}

void Virus::infect(Student* s)
{
	//attempt to make virus infect student and set states inside student**
	//had problems with friending the private variables
	//current_student = s;
	//current_student->state = INFECTED; 
	// (current_student->state) = 2;
	// (current_student->antibodies) = 0;
	(this->state) = IN_STUDENT;
	//add parameters to delete antibodies later
}


bool Virus::get_variant()
{
	return variant;
}

double Virus::get_virulence()
{
	return virulence;
}

double Virus::get_resistance()
{
	return resistance;
}

double Virus::get_energy()
{
	return energy;
}

bool Virus::get_in_student()
{
	return is_in_student;
}

//updates the state of the virus
bool Virus::Update()
{
	//attempt at making virus latch onto student**
	// if (location.x == current_student->GetLocation().x && location.y == current_student->GetLocation().y)
	// {
	// 	infect(current_student);
	// 	// SetupDestination(current_student->getDestination());
	// 	cout << "Virus just entered student and now they have no antibodies :'(" << endl;
	// }
	switch (state)
	{
		case IN_ENVIRONMENT:
			return false;
			break;
		case DEAD:
			cout << "Virus is dead" << endl;
			return true;
			break;
		case IN_STUDENT:
			cout << "Virus in student" << endl;

			return true;
			break;
		default:
			return false;
			break;
	}
}

// void Virus::SetupDestination(Point2D dest) //attempt to make virus follow student**
// {
// 	virus_destination.x = dest.x;
// 	virus_destination.y = dest.y;
// 	virus_delta = (virus_destination - (this->location)) * (speed / GetDistanceBetween(virus_destination, (this->location)));
// }

void Virus::ShowStatus()
{
	cout << "Virus status:" << endl;
	GameObject::ShowStatus();
	switch (state)
	{
		case IN_ENVIRONMENT:
			cout << "Virus in environment" << endl;
			break;
		case DEAD:
			cout << "Virus is dead" << endl;
			break;
		case IN_STUDENT:
			cout << "Virus inside " << current_student->getName() << endl;
			break;
		default:
			break;
	}
}

bool Virus::IsAlive()
{
	if(energy > 0 || state == DEAD)
	{
		return true;
	}
	else
	{
		state = DEAD;
		return false;
	}
}

bool Virus::ShouldBeVisible()
{
	return IsAlive();
}