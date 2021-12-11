#include "Vector2D.h"

Vector2D::Vector2D(double in_x, double in_y)
:x(in_x), y(in_y)
{

}

Vector2D::Vector2D()
:x(0.0), y(0.0)
{

}


//overloaded operators
ostream& operator<<(ostream& os, const Vector2D& v)
{
	os << "<" << v.x << ", " << v.y << ">";
	return os;
}

Vector2D operator * (const Vector2D& v, const double& d)
{
	Vector2D out;
	out.x = v.x*d;
	out.y = v.y*d;
	return out;
}

Vector2D operator / (const Vector2D& v, const double& d)
{
	Vector2D out;
	out.x = v.x/d;
	out.y = v.y/d;
	return out;
}