#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

#include <iostream>

using namespace std;

class GameObject
{
	protected:
		Point2D location;
		int id_num;
		char display_code;
		char state;
	public:
		GameObject();
		GameObject(char in_code);
		GameObject(Point2D in_loc, int in_id, char in_code);
		GameObject(char in_code, int id, Point2D in_loc); //ADDED FOR PA4
		// virtual ~GameObject(); //ERROR WHEN I DO THIS: BUT NEED FOR MEMORY LEAKS
		Point2D GetLocation();
		int GetId();
		char GetState();
		virtual void ShowStatus();
		virtual bool Update() = 0;
		virtual bool ShouldBeVisible() = 0;

		void DrawSelf(char* ptr);
};

#endif