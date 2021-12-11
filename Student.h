#ifndef STUDENT_H
#define STUDENT_H

#include "GameObject.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
// #include "Virus.h" //added for friend

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum StudentStates
{
	STOPPED = 0,
	MOVING = 1,
	INFECTED = 2,
	AT_DOCTORS = 3,
	IN_CLASS = 4,
	MOVING_TO_DOCTOR = 5,
	MOVING_TO_CLASS = 6,
	STUDYING_IN_CLASS = 7,
	RECOVERING_ANTIBODIES = 8
};

class Student: public GameObject
{
	private:
		double speed;
		bool is_at_doctor;
		bool is_in_class;
		unsigned int antibodies;
		unsigned int credits;
		double dollars;
		unsigned int assignments_to_buy;
		unsigned int vaccines_to_buy;
		string name;
		DoctorsOffice* current_office;
		ClassRoom* current_class;
		Point2D destination;
		Vector2D delta;
		// friend class Virus; //tried friend to make virus insta kill student by setting antibodies to 0
	public:
		Student();
		Student (char in_code);
		Student(string in_name, int in_id, char in_code, unsigned int in_speed,
 				Point2D in_loc);
		void StartMoving(Point2D dest);
		void StartMovingToClass(ClassRoom* classr);
		void StartMovingToDoctor(DoctorsOffice* office);
		void StartLearning(unsigned int num_assignments);
		void StartRecoveringAntibodies(unsigned int num_vaccines);
		void Stop();
		bool IsInfected();
		bool ShouldBeVisible();
		void ShowStatus();
		bool Update();
		string getName() const;
		//attempt to make virus latch on got too complicated**
		// Point2D getDestination() const; //added for virus to have same dest
		// Vector2D getDelta() const; //added for virus to have the same delta when latched on
		// double getSpeed() const; //added for virus to have same speed as student when latched on
	protected:
		bool UpdateLocation();
		void SetupDestination(Point2D dest);
};

static double GetRandomAmountOfDollars();

#endif