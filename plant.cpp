#include <fstream>
#include "plant_atd.h"

using namespace std;

namespace plants {
	// ��������� ��������� ������� �������
	bush* InBush(ifstream& ist);
	tree* InTree(ifstream& ist);
	flower* InFlower(ifstream& ist);
	void Out(bush& r, ofstream& ofst);
	void Out(tree& t, ofstream& ofst);
	void Out(flower& r, ofstream& ofst);
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
	// Сравнение для растений по количеству согласных букв
	bool Compare(plant& first, plant& second) {
		return first.cons < second.cons;
	}
	// Ввод параметров обобщенной фигуры из файла
	plant* InPlant(ifstream& ifst){
		plant* pl = new plant;
		int k,temp;
		ifst >> k;
		ifst >> pl->name;
		ifst >> temp;
		pl->pog = plant::place_of_growth(temp);
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
		case 3:
			pl->k = plant::key::FLOWER;
			pl->data = (void*)InFlower(ifst);
			return pl;
		default:
			return pl;
		}
	}
	// ����� ���������� ������� ������ � �����
	void Out(plant& s, ofstream& ofst) {
		ofst << "Name is " << s.name << ", ";
		ofst << "place of growth is ";
		switch (s.pog) {
		case plant::place_of_growth::Tundra:
			ofst << "Tundra ";
			break;
		case plant::place_of_growth::Taiga:
			ofst << "Taiga ";
			break;
		case plant::place_of_growth::Forest:
			ofst << "Forest ";
			break;
		case plant::place_of_growth::Steppe:
			ofst << "Steppe ";
			break;
		case plant::place_of_growth::Jungle:
			ofst << "Jungle ";
			break;
		default:
			ofst << "<Blank> ";
			break;
		}
		switch (s.k) {
		case plant::key::BUSH:
			Out(*(bush*)s.data, ofst);
			break;
		case plant::key::TREE:
			Out(*(tree*)s.data, ofst);
			break;
		case plant::key::FLOWER:
			Out(*(flower*)s.data, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
	}
} // end plants namespace