#include <fstream>
#include <iostream>
#include "bush_atd.h"
using namespace std;
namespace plants 
{
	bush* in_bush(ifstream& ifst)
	{
		bush* r = new bush;
		int temp;
		ifst >> temp;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}

		if (temp < 0 || temp > 11)
		{
			cout << "Error! Month should be value from range <0-11>" << endl;
			exit(1);
		}
		r->m = bush::flowering_month(temp);
		return r;
	}

	void out(bush& r, ofstream& ofst) 
	{
		ofst << "and it is bush: flowering month = ";
		switch (r.m) 
		{
		case 0:
			ofst << "January";
			break;
		case 1:
			ofst << "February";
			break;
		case 2:
			ofst << "March";
			break;
		case 3:
			ofst << "April";
			break;
		case 4:
			ofst << "May";
			break;
		case 5:
			ofst << "June";
			break;
		case 6:
			ofst << "July";
			break;
		case 7:
			ofst << "August";
			break;
		case 8:
			ofst << "September";
			break;
		case 9:
			ofst << "October";
			break;
		case 10:
			ofst << "November";
			break;
		case 11:
			ofst << "December";
			break;
		default:
			break;
		}
		ofst << endl;
	}
} // end plants namespace