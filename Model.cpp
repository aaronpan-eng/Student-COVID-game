#include "Model.h"

Model::Model()
{
	time = 0;
	//FORMAT: DoctorsOffice (int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc);
	Point2D D1p(1,20);
	DoctorsOffice* D1 = new DoctorsOffice(1,1,100,D1p);
	
	Point2D D2p(10,20);
	DoctorsOffice* D2 = new DoctorsOffice(2,2,200,D2p);
	
	//FORMAT: Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
	Point2D S1p(5,1);
	Student* S1 = new Student("Homer", 1, 'S', 2, S1p);
	
	Point2D S2p(10,1);
	Student* S2 = new Student("Marge", 2, 'S', 1, S2p);
	
	//FORMAT: ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc);
	Point2D C1p(0,0);
	ClassRoom* C1 = new ClassRoom(10, 1, 2, 3, 1, C1p);
	
	Point2D G2p(5,5);
	ClassRoom* G2 = new ClassRoom(20, 5, 7.5, 4, 2, G2p);

	//FORMAT: Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc)
	Point2D V1p(10,12);
	Virus* V1 = new Virus("deady virus 1", 5, 2, 10, false, 1, V1p);//ADDED IN PA4
	
	Point2D V2p(15,5);
	Virus* V2 = new Virus("deady virus 2", 5, 2, 10, false, 2, V2p);//ADDED IN PA4
	
	//pointers in linked list
	object_ptrs.push_back(S1);
	object_ptrs.push_back(S2);
	object_ptrs.push_back(D1);
	object_ptrs.push_back(D2);
	object_ptrs.push_back(C1);
	object_ptrs.push_back(G2);
	object_ptrs.push_back(V1);
	object_ptrs.push_back(V2);

	student_ptrs.push_back(S1);
	student_ptrs.push_back(S2);
	office_ptrs.push_back(D1);
	office_ptrs.push_back(D2);
	class_ptrs.push_back(C1);
	class_ptrs.push_back(G2);
	virus_ptrs.push_back(V1);
	virus_ptrs.push_back(V2);

	active_ptrs.push_back(S1);
	active_ptrs.push_back(S2);
	active_ptrs.push_back(D1);
	active_ptrs.push_back(D2);
	active_ptrs.push_back(C1);
	active_ptrs.push_back(G2);
	active_ptrs.push_back(V1);
	active_ptrs.push_back(V2);

	cout << "Model default constructed" << endl;
}

//OPTIONAL: add destructor messages for other classes as well
//says its for demonstration purposes: add if you have time
Model::~Model()
{
	cout << "Model destructed." << endl;
}

//These functions provide lookup and validation fo GameCommand (Controller)
//come back to these once you get to GameCommand

Student * Model::GetStudentPtr(int id)
{
	//iterating through list until the end of it
	//the rest follow formats like this
	list <Student*>::iterator iter;
	for (iter = student_ptrs.begin(); iter != student_ptrs.end(); iter++)
	{
		//checking if there is a valid id
		if ((*iter)->GetId() == id)
		{
			return *iter;
		}
	}
	//return NULL if the id is not found
	return NULL;
}

DoctorsOffice * Model::GetDoctorsOfficePtr(int id)
{
	list <DoctorsOffice*>::iterator iter;
	for (iter = office_ptrs.begin(); iter != office_ptrs.end(); iter++)
	{
		if ((*iter)->GetId() == id)
		{
			return *iter;
		}
	}
	return NULL;
}

ClassRoom * Model::GetClassRoomPtr(int id)
{
	list <ClassRoom*>::iterator iter;
	for (iter = class_ptrs.begin(); iter != class_ptrs.end(); iter++)
	{
		if ((*iter)->GetId() == id)
		{
			return (*iter);
		}
	}
	return NULL;

}

Virus * Model::GetVirusPtr(int id)
{
	list <Virus*>::iterator iter;
	for (iter = virus_ptrs.begin(); iter != virus_ptrs.end(); iter++)
	{
		if ((*iter)->GetId() == id)
		{
			return (*iter);
		}
	}
	return NULL;
}


bool Model::Update()
{
	//increment time first
	time++;

	//CHECKING IF THE GAME IS OVER
	//CHECKING ASSIGNMENTS LEFT
	//if no more assignments left -> GAME OVER
	int classcount = 0;
	for(list <ClassRoom*>::iterator iter = class_ptrs.begin(); iter != class_ptrs.end(); iter++)
	{
		if ((*iter)->passed() == true)
		{
			classcount++;
		}
	}
	if (classcount == class_ptrs.size())
	{
		cout << "GAME OVER: You win! All assignments done!" << endl;
		exit (EXIT_FAILURE);
	}

	//CHECKING HOW MANY STUDENTS ARE INFECTED
	//if all students infected -> GAME OVER
	int infected_count = 0;
	for (list <Student*>::iterator iter = student_ptrs.begin(); iter != student_ptrs.end(); iter++)
	{
		if (((*iter)->IsInfected()) == true)
		{
			infected_count++;
		}
	}
	if (infected_count == student_ptrs.size())
	{
		cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
		exit (EXIT_FAILURE);
	}
	
	//CLEANING OBJECTS THAT ARE INACTIVE
	for (list <GameObject*>::iterator iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
	{
		if (((*iter)->ShouldBeVisible()) == false)
		{
			iter = active_ptrs.erase(iter);
			cout << "Dead object removed" << endl;
		}
	}

	//UPDATING ALL OBJECTS
	int boolcount = 0;
	for (list <GameObject*>::iterator iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
	{
		// (*iter)->Update();
		if ((*iter)->Update() == true)
		{
			boolcount++;
		}
	}

	//BOOL RETURN FOR MODEL UPDATE
	//if any update returns true, then model update returns true
	if(boolcount > 0)
	{
		return true;
	}
	return false;
}

void Model::Display(View& view)
{
	cout << "current time: " << time << endl;

	view.Clear();

	for (list <GameObject*>::iterator iter = object_ptrs.begin(); iter != object_ptrs.end(); iter++)
	{
		view.Plot(*iter);
	}

	view.Draw();
}

void Model::ShowStatus()
{
	//SHOW STATUS FOR ALL OBJECTS
	for(list <ClassRoom*>::iterator iter = class_ptrs.begin(); iter != class_ptrs.end(); iter++)
	{
		(*iter)->ShowStatus();
	}
	for(list <Student*>::iterator iter = student_ptrs.begin(); iter != student_ptrs.end(); iter++)
	{
		(*iter)->ShowStatus();
	}
	for(list <DoctorsOffice*>::iterator iter = office_ptrs.begin(); iter != office_ptrs.end(); iter++)
	{
		(*iter)->ShowStatus();
	}

	//PRINTING TIME
	cout << "time: " << time << endl;
}

void Model::NewCommand(char in_type, int in_id, Point2D in_loc)
{
	//makes new object depening on if characters and id's are valid
	switch(in_type)
	{
		case 'd':
		{
			DoctorsOffice* NewOffice = new DoctorsOffice(in_id,1,100,in_loc);
			object_ptrs.push_back(NewOffice);
			office_ptrs.push_back(NewOffice);
			active_ptrs.push_back(NewOffice);
			break;
		}
		case 'c':
		{
			ClassRoom* NewClassroom = new ClassRoom(10, 1, 2, 3, in_id, in_loc);
			object_ptrs.push_back(NewClassroom);
			class_ptrs.push_back(NewClassroom);
			active_ptrs.push_back(NewClassroom);
			break;
		}
		case 's':
		{
			Student* NewStudent = new Student("New Student", in_id, 'S', 2, in_loc);
			object_ptrs.push_back(NewStudent);
			student_ptrs.push_back(NewStudent);
			active_ptrs.push_back(NewStudent);
			break;
		}
		case 'v':
		{
			Virus* NewVirus = new Virus("New Virus", 5, 2, 10, false, in_id, in_loc);
			object_ptrs.push_back(NewVirus);
			virus_ptrs.push_back(NewVirus);
			active_ptrs.push_back(NewVirus);
			break;
		}
	}
}
