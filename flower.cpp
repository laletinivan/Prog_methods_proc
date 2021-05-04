#include <fstream>
#include <iostream>
#include "flower_atd.h"
using namespace std;
namespace plants 
{
	flower* in_flower(ifstream& ifst) 
	{
		flower* r = new flower;
		int temp;
		ifst >> temp;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (temp < 0 || temp > 2)
		{
			cout << "Error! Type of flower should be value in range <0-2>!" << endl;
			exit(1);
		}
		r->t = flower::type(temp);
		return r;
	}

	void out(flower& r, ofstream& ofst) 
	{
		ofst << "and it is flower: type = ";
		switch (r.t) 
		{
		case 0:
			ofst << "Home";
			break;
		case 1:
			ofst << "Garden";
			break;
		case 2:
			ofst << "Wild";
			break;
		default:
			break;
		}
		ofst << endl;
	}
} // end plants namespace