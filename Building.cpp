#include "Building.h"

Building::Building()
:GameObject('B'), student_count(0)
{
	cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc)
:GameObject(in_loc, in_id, in_code), student_count(0)
{
	cout << "Building constructed" << endl;
}

void Building::AddOneStudent()
{
	student_count++;
}
void Building::RemoveOneStudent()
{
	student_count--;
}
void Building::ShowStatus()
{
	cout << display_code << id_num << " located at " << location << endl;
	cout << student_count << " students is/are in this building" << endl;
}
bool Building::ShouldBeVisible()
{
	return true;
}
