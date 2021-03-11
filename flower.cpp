#include "flower_atd.h"
using namespace std;
namespace plants {
	void flower::InData(ifstream& ifst) {
		int tmp;
		ifst >> tmp;
		pog = plant::place_of_growth(tmp);
		ifst >> tmp;
		t = flower::type(tmp);
	}
	void flower::Out(ofstream& ofst) {
		ofst << "Name is " << name << ", ";
		ofst << "number of consonants in name = " << cons << ", ";
		ofst << "place of growth is ";
		switch (pog) {
		case Tundra:
			ofst << "Tundra ";
			break;
		case Taiga:
			ofst << "Taiga ";
			break;
		case Forest:
			ofst << "Forest ";
			break;
		case Steppe:
			ofst << "Steppe ";
			break;
		case Jungle:
			ofst << "Jungle ";
			break;
		default:
			ofst << "<Blank> ";
			break;
		}
		ofst << "and it is flower: type = ";
		switch (t) {
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