#ifndef POINT2D_H
#define POINT2D_H

#include "Vector2D.h"

#include <cmath>
#include <iostream>

using namespace std;

//since that class Point2D is all public, I could make a struct instead because
//struct is just an all public varible class

// class Vector2D;	//forward declaration; need this for the 
					//non-member overloded op b/c it has Vector2D in it
					//if I do #include "Vector2D" then when I include Vector2D 
					//in main program, it would give a redeclaration error
					//UPDATE: actually I can do what i described above as long
					//as I do #ifndef POINT2D_H 
					//        #define POINT2D_H
					//     ****stuff in .h file******
					//		  #endif

class Point2D
{
	public:
		double x;
		double y;
		Point2D(double in_x, double in_y);
		Point2D();

};


//this is the non-member function
//non-member function means function not defined in the class itsself
double GetDistanceBetween(Point2D, Point2D);

//non-member overloaded operators
ostream& operator<<(ostream& os, const Point2D& p);
Point2D operator+ (Point2D& p, Vector2D& v);
Vector2D operator- (Point2D& p1, Point2D & p2);

#endif