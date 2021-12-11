#include "DoctorsOffice.h"

DoctorsOffice::DoctorsOffice():Building()
{
	display_code = 'D';				//this is an alternate way of initializing things
	vaccine_capacity = 100;			//imo it can look more intuitive
	num_vaccine_remaining = vaccine_capacity;
	dollar_cost_per_vaccine = 5;
	state = VACCINE_AVAILABLE;
	cout << "DoctorsOffice default constructed" << endl;
}

DoctorsOffice::DoctorsOffice (int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
:Building()
{
	display_code = 'D';
	vaccine_capacity = vaccine_cap;
	num_vaccine_remaining = vaccine_capacity;
	dollar_cost_per_vaccine = vaccine_cost;
	state = VACCINE_AVAILABLE;
	location = in_loc;		//here I split it up half after the class 
	id_num = in_id;			//and half in the body of the constructor

	cout << "DoctorsOffice constructed" << endl;
}

bool DoctorsOffice::HasVaccine()
{
	if (num_vaccine_remaining >= 1)
		return true;
	else
		return false;
}

unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
	return num_vaccine_remaining;
}

bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
	if (budget >= (vaccine*dollar_cost_per_vaccine))
		return true;
	else
		return false;
}

double DoctorsOffice::GetDollarCost(unsigned int vaccine)
{
	return vaccine*dollar_cost_per_vaccine;
}

unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
	if (num_vaccine_remaining >= vaccine_needed)//have to check this
	{
		num_vaccine_remaining -= vaccine_needed;
		return vaccine_needed;
	}
	else
	{
		unsigned int temp = num_vaccine_remaining;
		num_vaccine_remaining = 0;
		return temp;
	}
}
//will have to update this so that it will return true
//ONLY when doctors office has no vaccine left, and false
//for future calls
//UPDATE: I think I got it with adding && state == 0
bool DoctorsOffice::Update()
{
	if (num_vaccine_remaining == 0 && state == 0)
	{
		state = NO_VACCINE_AVAILABLE;
		display_code = 'd';
		cout << "DoctorsOffice " << id_num << " has ran out of vaccine" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void DoctorsOffice::ShowStatus()
{
	cout << "DoctorsOffice Status: " << endl;
	Building::ShowStatus();
	cout << "Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
	cout << "has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}

//extra questions:
//is there a way to initalize all variables in default constructor
//after the :   ?

//does the DoctorsOffice default constructor have default coordinates?
//	yes its (0, 0)