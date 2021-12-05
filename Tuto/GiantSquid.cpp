#include <iostream>
#include <fstream>
#include <string>
#include <vector>


const std::vector<int> randomNums = { 31,50,68,16,25,15,28,80,41,
8,75,45,96,9,3,98,83,27,62,42,
59,99,95,13,55,10,23,84,18,76,
87,56,88,66,1,58,92,89,19,54,
85,74,39,93,77,26,30,52,69,48,
91,73,72,38,64,53,32,51,6,29,
17,90,34,61,70,4,7,57,44,97,
82,37,43,14,81,65,11,22,5,36,
71,35,78,12,0,94,47,49,33,79,
63,86,40,21,24,46,20,2,67,60 };

class BingoBoard
{
private:
	std::vector<std::vector<int>> m_board;
	std::vector<std::vector<int>> m_counts;
	int m_lastNum = -1;
public:
	BingoBoard(std::ifstream& initVals)
	{
		for (int i = 0; i < 5; i++) {
			std::vector<int> temp;
			int tInt;
			for (int j = 0; j < 5; j++) {
				initVals >> tInt;
				temp.push_back(tInt);
			}
			this->m_board.push_back(temp);
		}
		this->m_counts.push_back({ 0,0,0,0,0 });
		this->m_counts.push_back({ 0,0,0,0,0 });
	}

	bool call(int num) {
		std::vector<std::vector<int>> pos = this->searchBoard(num);
		if (pos[0][0] == -1)
			return false;
		
		this->m_lastNum = num;

		for (std::vector<int> iVect : pos) {
			this->m_board[iVect[0]][iVect[1]] += 100;
			this->m_counts[0][iVect[0]]++;
			this->m_counts[1][iVect[1]]++;
		}

		return checkBingo();
	}

	int getAnswer() {
		int sum = 0;
		for (std::vector<int>& iVect : this->m_board) {
			for (int& n : iVect) {
				sum += (n < 100) ? n : 0;
			}
		}
		return sum * this->m_lastNum;
	}

private:
	std::vector<std::vector<int>> searchBoard(int num) {
		std::vector<std::vector<int>> retVal;
		int c0 = 0;
		for (std::vector<int>& intVect : this->m_board) {
			int c1 = 0;
			for (int& n : intVect) {
				if (n == num) {
					retVal.push_back({ c0, c1 });
				}
				c1++;
			}
			c0++;
		}
		if (retVal.size() == 0)
			retVal.push_back({ { -1 } });
		return retVal;
	}

	bool checkBingo() {
		for (int& n : this->m_counts[0]) {
			if (n >= 5)
				return true;
		}
		for (int& n : this->m_counts[1]) {
			if (n >= 5)
				return true;
		}
		return false;
	}
};

void giantSquid() {
	std::ifstream inputs("GiantSquidInputs.txt");
	std::vector<BingoBoard> GameBoards;

	if (inputs.is_open())
	{
		while (EOF != inputs.peek()) {
			BingoBoard b(inputs);
			GameBoards.push_back(b);
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	for (const int n : randomNums) {
		for (BingoBoard& binB : GameBoards) {
			if (binB.call(n)) {
				std::cout << binB.getAnswer() << std::endl;
				goto exitGame;
			}
		}
	}
exitGame:
	while (GameBoards.size() > 1) {
		for (const int n : randomNums) {
			int count = 0;
			bool modified = false;
			for (BingoBoard& binB : GameBoards) {
				if (binB.call(n)) {
					GameBoards.erase(GameBoards.begin() + count);
					modified = true;
				}
				count++;
			}
			if (modified)
				goto exitGame;
		}
	}
	for (const int n : randomNums) {
		for (BingoBoard& binB : GameBoards) {
			if (binB.call(n)) {
				std::cout << binB.getAnswer() << std::endl;
				goto exitGame2;
			}
		}
	}
exitGame2:
	bool nop = false;
}