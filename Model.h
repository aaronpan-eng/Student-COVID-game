#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Student.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "View.h"
#include "Virus.h"

#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

class Model
{
	private:
		int time;
		
		//LINKED LISTS
		list <GameObject*> object_ptrs;
		list <GameObject*> active_ptrs;
		list <Student*> student_ptrs;
		list <DoctorsOffice*> office_ptrs;
		list <ClassRoom*> class_ptrs;
		list <Virus*> virus_ptrs;

	public:
		Model();
		~Model();
		Student * GetStudentPtr(int id); 
		DoctorsOffice * GetDoctorsOfficePtr(int id);
		ClassRoom * GetClassRoomPtr(int id); 
		Virus * GetVirusPtr(int id);
		bool Update();
		void Display(View& view);
		void ShowStatus();
		void NewCommand(char type, int in_id, Point2D in_loc);

};

#endif