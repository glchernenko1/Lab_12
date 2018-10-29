#pragma once
#include "polygon.h"

const double Pi = 3.141592;

class regular_polygon :public polygon
{
private:
	double size;
	point core;

public:
	regular_polygon(int n=3, double size=0, point core= point(0,0));
	double get_size() const { return size; }
	point get_core() const { return core; }
	bool Convex() const override { return true; };

	double r() const { return operator[](0).distance_to(operator[](1)) / 2 / sin(Pi / size); }
	double R() const { return operator[](0).distance_to(operator[](1)) / 2 / tan(Pi / size); }
	friend std::istream &operator>>(std::istream &is, regular_polygon &p)
	{
		int n, len;
		point a;
		is >> n >> a >> len;
		p = regular_polygon(n, len,a);
		return is;
	}
};



class quad:public polygon
{
private:
	double dlin;
	double h;
public:
	quad(point a = point(0, 0), point b=point(0,0));
	
	quad(point a, double dlin, double h);
	double get_dlin() { return dlin; }
	double get_h() { return h; }
	double P() const  override { return 2 * (dlin + h); }
	double S() const override { return dlin * h; }
	double R() const {return sqrt(dlin*dlin + h * h) / 2;}
	double r() const { if (h != dlin) throw std::logic_error("НЕ квадрат"); return h / 2; }
	friend std::istream &operator>>(std::istream &is, quad &p)
	{
		point a, b;
		is >> a >> b;
		p = quad(a, b);
		return is;
	}
};

