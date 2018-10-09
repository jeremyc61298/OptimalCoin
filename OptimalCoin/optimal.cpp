// ------------------------------
// optimal.cpp
// Jeremy Campbell
// Description ...
// ------------------------------
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

int main()
{
	ifstream fin("optimal.in");
	if (!fin.is_open())
	{
		cerr << "Failed to open necessary files. " << endl;
		return -1;
	}
	ofstream fout("optimal.out");


}