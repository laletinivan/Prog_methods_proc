#include <fstream>
#include "plant_atd.h"

using namespace std;

namespace plants {
	// Сигнатуры требуемых внешних функций
	bush* InBush(ifstream& ist);
	tree* InTree(ifstream& ist);
	void Out(bush& r, ofstream& ofst);
	void Out(tree& t, ofstream& ofst);
	// Количество согласных букв
	int Consanants(plant& p) {
		string vowel = "AEIOUaeiou";
		int count = 0;
		for (int i = 0; i < p.name.length(); i++) {
			if (vowel.find(p.name[i]) == string::npos) {
				count++;
			}
		}
		return count;
	}
	// Ввод параметров обобщенной фигуры из файла
	plant* InPlant(ifstream& ifst){
		plant* pl = new plant;
		int k;
		ifst >> k;
		ifst >> pl->name;
		pl->cons = Consanants(*pl);
		switch (k) {
		case 1:
			pl->k = plant::key::BUSH;
			pl->data = (void*)InBush(ifst);
			return pl;
		case 2:
			pl->k = plant::key::TREE;
			pl->data = (void*)InTree(ifst);
			return pl;
		default:
			return pl;
		}
	}
	// Вывод параметров текущей фигуры в поток
	void Out(plant& s, ofstream& ofst) {
		ofst << "Name is " << s.name << ", ";
		ofst << "number of consonants in name = " << s.cons << ", ";
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