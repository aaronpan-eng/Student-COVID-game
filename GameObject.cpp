#include "GameObject.h"
#include "Point2D.h"

GameObject::GameObject()
:display_code('S'), id_num(1), state(0)
{
	location.x = 0; //added later
	location.y = 0; //added later
	cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code)
:display_code(in_code), id_num(1), state(0) 
{
	location.x = 0; //added later
	location.y = 0; //added later
	cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
:location(in_loc), id_num(in_id), display_code(in_code), state(0)
{
	cout << "GameObject constructed" << endl;
}

GameObject::GameObject(char in_code, int id, Point2D in_loc) //ADDED FOR PA4
{
	display_code = in_code;
	id_num = id;
	location.x = in_loc.x;
	location.y = in_loc.y;
	cout << "GameObject constructed" << endl;
}

Point2D GameObject::GetLocation()
{
	return location;				
}

int GameObject::GetId()
{
	return id_num;
}

char GameObject::GetState()
{
	return state;
}

void GameObject::ShowStatus()
{
	cout << display_code << id_num << " at " << location << endl;
}


//extra questions:
//what happens if I define the constructors after the member functions? doesnt matter
	//will it mess up member functions defined before constructors? doesnt matter

void GameObject::DrawSelf(char* ptr)
{
	*ptr = display_code;
	*(ptr + 1) = ('0' + id_num);
}