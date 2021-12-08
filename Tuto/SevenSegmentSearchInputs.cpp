#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

/*
 000 
1   2
1   2
1   2
 333 
4   5
4   5
4   5
 666 
*/

int decodeEasy(std::string& segBits) {
	int val = segBits.size();
	switch (val)
	{
	case 2:
		return 1;
	case 3:
		return 7;
	case 4:
		return 4;
	case 5:
		return -5;
	case 6:
		return -6;
	case 7:
		return 8;
	default:
		break;
	}
	std::cout << "Error on decodeEasy! Value: " << val << std::endl;
	return -10;
}

int decodeHard(std::vector<std::pair<std::string, int>>& encodedValues) {
	std::vector<std::string> possibleValuesPerSegment;
	std::map<int, std::string> formattedValues;
	std::vector<std::string> solverPairs;
	for (int i = 0; i < 7; i++) {
		possibleValuesPerSegment.push_back(std::string());
	}
	for (std::pair<std::string, int> pSegBits : encodedValues) {
		if (std::get<1>(pSegBits) < 0)
			solverPairs.push_back(std::get<0>(pSegBits));
		if (std::get<1>(pSegBits) < 0)
			continue;
		formattedValues.emplace(std::get<1>(pSegBits), std::get<0>(pSegBits));
	}
	possibleValuesPerSegment[0] = formattedValues[7];
	possibleValuesPerSegment[0].erase(std::remove(possibleValuesPerSegment[0].begin(), possibleValuesPerSegment[0].end(), formattedValues[1][0]), possibleValuesPerSegment[0].end());
	possibleValuesPerSegment[0].erase(std::remove(possibleValuesPerSegment[0].begin(), possibleValuesPerSegment[0].end(), formattedValues[1][1]), possibleValuesPerSegment[0].end());
	possibleValuesPerSegment[1] = formattedValues[4];
	possibleValuesPerSegment[1].erase(std::remove(possibleValuesPerSegment[1].begin(), possibleValuesPerSegment[1].end(), formattedValues[1][0]), possibleValuesPerSegment[1].end());
	possibleValuesPerSegment[1].erase(std::remove(possibleValuesPerSegment[1].begin(), possibleValuesPerSegment[1].end(), formattedValues[1][1]), possibleValuesPerSegment[1].end());
	possibleValuesPerSegment[2] = formattedValues[1];
	possibleValuesPerSegment[3] = possibleValuesPerSegment[1];
	possibleValuesPerSegment[4] = formattedValues[8];
	possibleValuesPerSegment[4].erase(std::remove(possibleValuesPerSegment[4].begin(), possibleValuesPerSegment[4].end(), possibleValuesPerSegment[0][0]), possibleValuesPerSegment[4].end());
	possibleValuesPerSegment[4].erase(std::remove(possibleValuesPerSegment[4].begin(), possibleValuesPerSegment[4].end(), possibleValuesPerSegment[1][0]), possibleValuesPerSegment[4].end());
	possibleValuesPerSegment[4].erase(std::remove(possibleValuesPerSegment[4].begin(), possibleValuesPerSegment[4].end(), possibleValuesPerSegment[1][1]), possibleValuesPerSegment[4].end());
	possibleValuesPerSegment[4].erase(std::remove(possibleValuesPerSegment[4].begin(), possibleValuesPerSegment[4].end(), formattedValues[1][0]), possibleValuesPerSegment[4].end());
	possibleValuesPerSegment[4].erase(std::remove(possibleValuesPerSegment[4].begin(), possibleValuesPerSegment[4].end(), formattedValues[1][1]), possibleValuesPerSegment[4].end());
	possibleValuesPerSegment[5] = formattedValues[1];
	possibleValuesPerSegment[6] = possibleValuesPerSegment[4];
	

}

void sevenSegmentSearch() {
	std::ifstream inputs("SevenSegmentSearchInputs.txt");
	std::vector<std::vector<std::vector<std::pair<std::string, int>>>> bigData;
	std::string displayBits;
	int count = 0;

	if (inputs.is_open())
	{
		int lineCount = 0;
		int segCount = 0;
		// Read input file to vector
		while (inputs >> displayBits)
		{
			if (segCount < 10) {
				if ((int)bigData.size() < lineCount + 1) {
					bigData.push_back(std::vector<std::vector<std::pair<std::string, int>>>());
					bigData[lineCount].push_back(std::vector<std::pair<std::string, int>>());
					bigData[lineCount].push_back(std::vector<std::pair<std::string, int>>());
				}
				bigData[lineCount][0].push_back(std::make_pair(displayBits, decodeEasy(displayBits)));
			}
			else if (segCount > 10) {
				bigData[lineCount][1].push_back(std::make_pair(displayBits, decodeEasy(displayBits)));
			}
			if (segCount < 11) {
			}
			else if (displayBits.size() == 2 || displayBits.size() == 3 ||
				displayBits.size() == 4 || displayBits.size() == 7)
			{
				count++;
			}
			segCount++;
			if (segCount == 15)
			{
				// Decode Hard Here !!!!!!!!!!!!
				int temp = decodeHard(bigData[lineCount][0]);
				lineCount++;
				segCount = 0;
			}
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	std::cout << count << std::endl;
}