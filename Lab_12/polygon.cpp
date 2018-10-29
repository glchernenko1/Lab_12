#include <cmath>
#include <exception>
#include <iostream>
#include "polygon.h"

using namespace std;

//
// Методы
//

point::point() : x(0.0), y(0.0)
{
	//cout << "Создана точка (0,0)" << endl;
}

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
	//cout << "Создана точка ( " << x << " , " << y << " )" << endl;
}

point::point(const point &p) : x(p.x), y(p.y)
{
	//cout << "Создана копия ( " << x << " , " << y << " )" << endl;
}

point::~point()
{
	//cout << "Уничтожена точка ( " << x << " , " << y << " )" << endl;
}

double point::distance_to(const point &target) const
{
	return sqrt((x - target.x)*(x - target.x) + (y - target.y)*(y - target.y));
}

double point::get_x() const
{
	return x;
}

double point::get_y() const
{
	return y;
}


void point::set_x(double x) 
{
	this->x = x;
}

void point::set_y(double y) 
{
	this->y = y;
}



//
// Операции
//

bool operator==(const point &p1, const point &p2)
{
	return abs(p1.get_x() - p2.get_x()) < precision &&
		abs(p1.get_y() - p2.get_y()) < precision;
}

bool operator!=(const point &p1, const point &p2)
{
	return !(p1 == p2);
}

std::ostream &operator<<(std::ostream &os, const point &p)
{
	os << p.get_x() << " " << p.get_y() << " ";
	return os;
}

std::istream &operator>>(std::istream &is, point &p)
{
	is >> p.x >> p.y;
	return is;
}

//
// Глобальные фуекции
//

point get_point()
{
	double x, y;
	std::cin >> x >> y;
	if (!std::cin)
		throw std::domain_error("Некорректные координаты точки");
	return point(x, y);
}

void print(const point & p)
{
	std::cout << "(" << p.get_x() << ", " << p.get_y() << ")";
}

ostream & operator<<(std::ostream & os, const polygon & p)

{
	os << p.sz<<" ";
	for (int i=0; i<p.sz; ++i)
	{
		os << p.peak[i];
	}
	return os;
}

std::istream & operator>>(std::istream & is, polygon & p)
{
	is >> p.sz;
	delete[]p.peak;
	p.peak = new  point[p.sz];
	for (int i = 0; i < p.sz; ++i)
	{
		is >> p.peak[i];
	}
	return is;
}

bool polygon::operator==(polygon a)
{
	int i = 0;
	if (sz == a.sz)
		while (peak[i] == a.peak[i] && i < sz) ++i;
	return (i == sz);
}

bool polygon::operator!=(polygon a)
{
	int i = 0;
	if (sz != a.sz) return true;
	else
		while (peak[i] != a.peak[i] && i < sz) ++i;
	return (i != sz);
}
