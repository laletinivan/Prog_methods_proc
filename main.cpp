#include <iostream>
#include <fstream>
#include "container_atd.h"

using namespace std;

namespace plants {
	// Сигнатуры требуемых внешних функций
	void init(container& c);
	void clear(container& c);
	void in(container& c, ifstream& ifst);
	void out(container& c, ofstream& ofst);
	void out_bush(container& c, ofstream& ofst);
	void sort(container& c);
	void multimethod(container& c, ofstream& ofst);
}

using namespace plants;

int main(int argc, char* argv[]) {
	if (argc != 3) 
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	if (!ifst.is_open())
	{
		cout << "Could not to open input file!" << endl;
		return 1;
	}
	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		cout << "Could not to open output file!" << endl;
		return 1;
	}
	cout << "Start" << endl;
	container c;
	init(c);
	in(c, ifst);
	ofst << "Filled container. " << endl;
	sort(c);
	out(c, ofst);
	out_bush(c, ofst);
	multimethod(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}