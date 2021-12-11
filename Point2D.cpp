#include "Point2D.h"

Point2D::Point2D(double in_x, double in_y)
:x(in_x), y(in_y)
{

}

Point2D::Point2D()
:x(0.0), y(0.0)
{

}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
	return sqrt(pow((p2.x - p1.x),2)+pow((p2.y - p1.y),2));
}


//overloaded operators
ostream& operator << (ostream& os, const Point2D& p1)
{
	os << "(" << p1.x << ", " << p1.y << ")";
	return os;
}

Point2D operator+ (Point2D& p, Vector2D& v)
{
	Point2D new_p;
	new_p.x = p.x + v.x;
	new_p.y = p.y + v.y;
	return new_p;
}

Vector2D operator- (Point2D& p1, Point2D & p2)
{
	Vector2D new_p;
	new_p.x = p1.x - p2.x;
	new_p.y = p1.y - p2.y;
	return new_p;
}