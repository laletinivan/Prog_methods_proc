#include "flower_atd.h"
#include <fstream>
using namespace std;
namespace plants {
	flower* InFlower(ifstream& ifst) {
		flower* r = new flower;
		int temp;
		ifst >> temp;
		r->t = flower::type(temp);
		return r;
	}

	void Out(flower& r, ofstream& ofst) {
		ofst << "and it is flower: type = ";
		switch (r.t) {
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