#include <fstream>
#include "tree_atd.h"
using namespace std;
namespace plants {
	// ���� ���������� ������������ �� ������
	tree* InTree(ifstream& ifst)
	{
		tree* t = new tree;
		ifst >> t->age;
		return t;
	}
	// ����� ���������� ������������ � �����
	void Out(tree& t, ofstream& ofst)
	{
		ofst << "and it is tree: age = " << t.age << endl;
	}
} // end plants namespace