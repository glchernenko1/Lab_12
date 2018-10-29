#include "treangl.h"

void treangl::tipeTriangl()
{
	
		double a = get_p1().distance_to(get_p2());
		double b = get_p2().distance_to(get_p3());
		double c = get_p3().distance_to(get_p1());
		if (abs(a*a - (b * b + c * c)) <= 0.00001 || abs(b * b - (a * a + c * c)) <= 0.00001 || abs(c * c - (b * b + a * a)) <= 0.00001)
			std::cout << "Прямоугольник" << std::endl;
		else
			if (a*a > b*b + c * c || b * b > a*a + c * c || c * c > b*b + a * a)
				std::cout << "Тупоугольник" << std::endl;
			else
				std::cout << "Остроугольки" << std::endl;


	
}
