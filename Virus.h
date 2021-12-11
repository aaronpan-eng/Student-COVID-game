#ifndef VIRUS_H
#define VIRUS_H

#include "Point2D.h"
#include "Student.h"

#include <iostream>

using namespace std;

#include "Student.h"

enum VirusStates
{
	IN_ENVIRONMENT = 0,
	DEAD = 1,
	IN_STUDENT = 2
};

class Virus: public GameObject
{
protected:
	double virulence;
	double resistance;
	bool variant;
	double energy;
	bool is_in_student;
	string name;
	Student * current_student;
	//attempt to make virus latch onto student**
	// Point2D virus_destination; //added for virus to latch onto student for 1 destination
	// Vector virus_delta; //added for virus to have same delta as student
public:
	Virus(string name, double virulence, double resistance, double energy,
		  bool variant, int id, Point2D in_loc);
	void infect(Student* s);
	bool get_variant();
	double get_virulence();
	double get_resistance();
	double get_energy();
	bool get_in_student();
	bool Update();
	void ShowStatus();
	bool IsAlive();
	bool ShouldBeVisible();
	void SetupDestination(Point2D dest); //added for virus to match student destination
};

#endif