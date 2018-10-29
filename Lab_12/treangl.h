#pragma once
#include "polygon.h"
class treangl:public polygon
{
public:
	treangl() :polygon(3) {};

	treangl(point *a) :polygon(a, 3) {};
	point get_p1() const { return polygon::operator[](1);}
	point get_p2() const { return polygon::operator[](2);}
	point get_p3() const { return polygon::operator[](3);}
	void tipeTriangl();
	bool Convex() const override { return true; };

	friend std::istream &operator>>(std::istream &is, treangl &p)
	{
		is >> p[0] >> p[1] >> p[2];
		return is;
	}
private:

};

