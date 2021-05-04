#include <fstream>
#include <iostream>
#include "tree_atd.h"
using namespace std;
namespace plants 
{
	// Ввод параметров треугольника из потока
	tree* in_tree(ifstream& ifst)
	{
		int tmp_age;
		tree* t = new tree;
		ifst >> tmp_age;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}

		if (tmp_age < 0)
		{
			cout << "Error! Age cant be negative!" << endl;
			exit(1);
		}
		t->age = tmp_age;
		return t;
	}
	// Вывод параметров треугольника в поток
	void out(tree& t, ofstream& ofst)
	{
		ofst << "and it is tree: age = " << t.age << endl;
	}
} // end plants namespace