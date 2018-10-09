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

void readCoins(stringstream &s, const int numCoins, vector<unsigned short> &coins)
{
	for (int i = 0; i < numCoins; i++)
	{
		s >> coins[i];
	}
}

int findMaxScore(vector<unsigned short> &coins)
{
	int maxScore = 0;
	
	
	return maxScore;
}

int playCoins(string line)
{
	stringstream s(line);
	int numCoins;
	s >> numCoins;

	vector<unsigned short> coins(numCoins);
	readCoins(s, numCoins, coins);
	return findMaxScore(coins);
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
	
	while (line[0] != '0')
	{
		int maxScore = playCoins(line);
		fout << maxScore;

		getline(fin, line);
		if (line[0] != '0')
			cout << endl;
	}
}