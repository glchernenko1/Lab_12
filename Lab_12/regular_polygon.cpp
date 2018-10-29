#include "regular_polygon.h"

regular_polygon::regular_polygon(int n, double size, point  core) :size(size), core(core), polygon(n)
{
	
	double r = size / 2 / sin(Pi / n);
	for (int i = 0; i < n; ++i)
	{
		operator[](i).set_x(r*cos((2 * Pi*(i + 1)) / n )+core.get_x());
		operator[](i).set_y(r*sin((2 * Pi*(i + 1)) / n)+core.get_y());
		
	}
	
}

quad::quad(point a, point b) :polygon(4)
{
	operator[](0) = a;
	operator[](1) = a;
	operator[](1).set_x(b.get_x());
	operator[](2) = b;
	operator[](3) = a;
	operator[](3).set_y(b.get_y());
	dlin = operator[](2).distance_to(operator[](3));
	h = operator[](0).distance_to(operator[](3));
}

quad::quad(point a, double dlin, double h):dlin(dlin), h(h), polygon(4)
{
	operator[](0) = a;
	operator[](1) = a;
	operator[](1).set_x(a.get_x() +dlin);
	operator[](2) = operator[](1);
	operator[](2).set_y(operator[](1).get_y()-h);
	operator[](3).set_y(a.get_y() - h);
}

