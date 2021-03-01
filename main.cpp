#include <iostream>
#include <fstream>
#include "container_atd.h"

using namespace std;

namespace plants {
	// Сигнатуры требуемых внешних функций
	void Init(container& c);
	void Clear(container& c);
	void In(container& c, ifstream& ifst);
	void Out(container& c, ofstream& ofst);
}

using namespace plants;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}