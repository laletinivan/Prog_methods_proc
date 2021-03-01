#include <fstream>
#include "plant_atd.h"

using namespace std;

namespace plants {
	// Сигнатуры требуемых внешних функций
	bush* InBush(ifstream& ist);
	tree* InTree(ifstream& ist);
	void Out(bush& r, ofstream& ofst);
	void Out(tree& t, ofstream& ofst);
	// Ввод параметров обобщенной фигуры из файла
	plant* InPlant(ifstream& ifst){
		plant* pl = new plant;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			ifst >> pl->name;
			pl->k = plant::key::BUSH;
			pl->data = (void*)InBush(ifst);
			return pl;
		case 2:
			ifst >> pl->name;
			pl->k = plant::key::TREE;
			pl->data = (void*)InTree(ifst);
			return pl;
		default:
			return pl;
		}
	}
	// Вывод параметров текущей фигуры в поток
	void Out(plant& s, ofstream& ofst) {
		ofst << "Name is " << s.name << " ";
		switch (s.k) {
		case plant::key::BUSH:
			Out(*(bush*)s.data, ofst);
			break;
		case plant::key::TREE:
			Out(*(tree*)s.data, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
	}
} // end plants namespace