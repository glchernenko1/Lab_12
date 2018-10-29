#include <iostream>
#include <fstream>
#include "polygon.h"
#include "regular_polygon.h"
#include <fstream>
#include "treangl.h"
//#include "crtdynmem.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("test.txt");
	int n;
	file >> n;
	char D;
	for (int i = 0; (file)&&i < n; ++i)
	{
		file >> D;
		switch (D)
		{
		case 'P':
		{
			regular_polygon A;
			file >> A;
			cout << A.P() << " " << A.S() << endl;
			break;
		}
		case 'T':
		{
			treangl A;
			file >> A;
			cout << A.P() << " " << A.S() << endl;
			break;
		}
		case 'R':
		{
			quad A;
			file >> A;
			cout << A.P() << " " << A.S() << endl;
			break;
		}
		default:
			break;
		}
	}
	
	system("pause");
 	return 0;
}