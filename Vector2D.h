#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;

class Vector2D
{
	public:
		double x;
		double y;
		Vector2D(double in_x, double in_y);
		Vector2D();

		
};

//overloaded operators
ostream& operator<<(ostream& os, const Vector2D& v);
Vector2D operator * (const Vector2D& v, const double& d);
Vector2D operator / (const Vector2D& v, const double& d);

#endif
