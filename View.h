#ifndef VIEW_H
#define VIEW_H

#include "Student.h"

#include <iostream>

using namespace std;

const int view_maxsize = 20;

class View
{
	private:
		int size;
		double scale;
		Point2D origin;
		char grid[view_maxsize][view_maxsize][2];
		bool GetSubscripts(int &out_x, int &out_y, Point2D location);
	public:
		View();
		void Clear();
		void Plot(GameObject * ptr);
		void Draw();
};

#endif