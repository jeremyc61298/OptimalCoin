// -------------------------------------------------------------------
// coins.cpp
// Jeremy Campbell
// Practices usage of Dynamic programming through a coin game.
// The game is played by two opponents with a set of coins. Each 
// opponent may take one coin off of either the left or right of the 
// line of coins. To win, you must have the highest total value. 
// This program seeks to find the highest possible score you can 
// make given a set of coins and that you choose first. 
// -------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;
using std::max;
using std::min;

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
	vector<vector<int>> scores(coins.size(), vector<int>(coins.size(), 0));
	
	for (int diag = 0; diag < coins.size(); ++diag)
	{
		for (int row = 0; row < coins.size() - (diag + 1); row++)
		{
			// If it's the first diagonal, populate it with the coins vector
			if (diag == 0)
				scores[row][row] = coins[row];
			else if (diag == 1)
				scores[row][row + 1] = max(coins[row], coins[row + 1]);
			else if (diag > 1)
			{
				int col = row + diag;

				// Choice 1: you select the left coin in the sub problem (represented by coins[row])
				int option1 = scores[row + 1][col - 1]; // Best possible score if opponent takes right coin
				int option2 = scores[row - 2][col];		// Best possible score if opponent takes new left coin
				int choice1 = coins[row] + min(option1, option2);

				// Choice 2: you select the right coin in the sub problem (represented by coins[col])
				option1 = scores[row][col - 2];		// Best possible score if opponent takes left coin
				option2 = scores[row + 1][col - 1];	// Best possible score if opponent takes new right coin
				int choice2 = coins[col] + min(option1, option2);

				scores[row][col] = max(choice1, choice2);
			}
		}
	}
	maxScore = scores[0][coins.size() - 1];
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
			fout << endl;
	}
}