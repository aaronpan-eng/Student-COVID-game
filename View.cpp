#include "View.h"

View::View()
:size(11), scale(2)
{
	origin.x = 0;
	origin.y = 0;
}

void View::Clear()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::Plot(GameObject * ptr)
{
	int x, y;
	bool validity = GetSubscripts(x, y, ptr->GetLocation());
	if (validity && grid[x][y][0] == '.')
	{
		ptr->DrawSelf(grid[x][y]);
	}
	else if (validity)
	{
		grid[x][y][0] = '*';
		grid[x][y][1] = ' ';
	}
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	Vector2D subscript;
	//truncating the location and origin & calculating difference
	subscript.x = (int(location.x) - int(origin.x))/scale;
	subscript.y = (int(location.y) - int(origin.y))/scale;

	//scale is a double, need to truncate again below:
	subscript.x = int(subscript.x); 
	subscript.y = int(subscript.y);

	//assign subscript to out_x and out_y
	out_x = subscript.x;
	out_y = subscript.y;
	
	if (subscript.x < (scale * size) && subscript.y < (size * scale))
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display" << endl;
		return false;
	}

}

void View::Draw()
{
	for (int j = size; j >= -1; j--)
	{
		for (int i = -1; i <= size-1; i++)
		{
			if (i == -1 && j%2 == 0)
			{
				cout << j*2;
				if (j/5 == 0)
				{
					cout << " ";
				}
			}
			else if (i == -1 && j%2 != 0)
			{
				cout << "  ";
			}
			else if (j == -1 && i%2 == 0)
			{
				cout << i*2;
				if (i/5 == 0)
				{
					cout << " ";
				}
				cout << "  ";
			}

			if (i >= 0 && j >= 0)
			{
				cout << grid[i][j][0] << grid[i][j][1];
			}
		}
		cout << endl;
	}
}