// ------------------------------
// coins.cpp
// Jeremy Campbell
// Description ...
// ------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

void readCoins(stringstream &s, const int numCoins, vector<int> &coins)
{

}

int main()
{
	ifstream fin("coins.in");
	if (!fin.is_open())
	{
		cerr << "Failed to open necessary files. " << endl;
		return -1;
	}
	ofstream fout("coins.out");
	
	// Get the first line from the file
	// and check whether numCoins is 0
	string line;
	getline(fin, line);
	stringstream s(line);
	int numCoins;
	s >> numCoins;

	while (numCoins != 0)
	{
		vector<int> coins(numCoins);
		readCoins(s, numCoins, coins);

		
	}
}