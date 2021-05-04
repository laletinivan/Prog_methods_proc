#include <fstream>
#include <iostream>
#include "plant_atd.h"

using namespace std;

namespace plants 
{
	bush* in_bush(ifstream& ist);
	tree* in_tree(ifstream& ist);
	flower* in_flower(ifstream& ist);
	void out(bush& r, ofstream& ofst);
	void out(tree& t, ofstream& ofst);
	void out(flower& r, ofstream& ofst);
	// Количество согласных букв
	int Consanants(plant& p) 
	{
		string vowel = "AEIOUaeiou";
		int count = 0;
		for (int i = 0; i < p.name.length(); i++) 
		{
			if (vowel.find(p.name[i]) == string::npos) 
			{
				count++;
			}
		}
		return count;
	}
	// Сравнение для растений по количеству согласных букв
	bool compare(plant& first, plant& second) 
	{
		return first.cons < second.cons;
	}
	// Ввод параметров обобщенной фигуры из файла
	plant* in_plant(ifstream& ifst)
	{
		plant* pl = new plant;
		int k, place;
		string tmp_name;
		ifst >> k;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}

		if (k < 1 || k > 3)
		{
			cout << "Error! Type number should be value from range <1-3>!" << endl;
			exit(1);
		}
		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		pl->name = tmp_name;
		ifst >> place;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (place < 0 || place > 4)
		{
			cout << "Error! Location number should be value from range <0-4>!" << endl;
			exit(1);
		}
		pl->pog = plant::place_of_growth(place);
		pl->cons = Consanants(*pl);
		switch (k) 
		{
		case 1:
			pl->k = plant::key::BUSH;
			pl->data = (void*)in_bush(ifst);
			return pl;
		case 2:
			pl->k = plant::key::TREE;
			pl->data = (void*)in_tree(ifst);
			return pl;
		case 3:
			pl->k = plant::key::FLOWER;
			pl->data = (void*)in_flower(ifst);
			return pl;
		default:
			return pl;
		}
	}
	void out(plant& s, ofstream& ofst) 
	{
		ofst << "Name is " << s.name << ", ";
		ofst << "number of cons is " << s.cons << ", ";
		ofst << "place of growth is ";
		switch (s.pog) 
		{
		case plant::place_of_growth::TUNDRA:
			ofst << "Tundra ";
			break;
		case plant::place_of_growth::TAIGA:
			ofst << "Taiga ";
			break;
		case plant::place_of_growth::FOREST:
			ofst << "Forest ";
			break;
		case plant::place_of_growth::STEPPE:
			ofst << "Steppe ";
			break;
		case plant::place_of_growth::JUNGLE:
			ofst << "Jungle ";
			break;
		default:
			ofst << "<Blank> ";
			break;
		}
		switch (s.k) 
		{
		case plant::key::BUSH:
			out(*(bush*)s.data, ofst);
			break;
		case plant::key::TREE:
			out(*(tree*)s.data, ofst);
			break;
		case plant::key::FLOWER:
			out(*(flower*)s.data, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
	}
} // end plants namespace