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

int getId(std::string str) {
	int sum = 0;
	for (const char c : str) {
		sum += std::pow(10, ((int)c - 97));
	}
	return sum;
}

int findByValue(std::map<int, std::string> mapOfElemen, int value)
{
	auto it = mapOfElemen.begin();
	// Iterate through the map
	while (it != mapOfElemen.end())
	{
		// Check if value of this entry matches with given value
		if (getId(it->second) == value)
		{
			// Yes found
			return it->first;
		}
		// Go to next entry in map
		it++;
	}
}

bool fitsIn(std::string& segBits, std::string& solvedSegBits) {
	bool fits = true;
	for (const char c : solvedSegBits) {
		if (segBits.find(c) == std::string::npos) {
			fits = false;
			break;
		}
	}
	return fits;
}

int decodeEasyStep3(std::string& segBits, std::map<int, std::string>& solvedSeg) {
	if (segBits == "") {
		return -2;
	}
	if (fitsIn(solvedSeg[9], segBits)) {
		return 5;
	}
	else {
		return 2;
	}
}

int decodeEasyStep2(std::string& segBits, std::map<int, std::string>& solvedSeg) {
	int val = segBits.size();
	if (val == 0) {
		return -2;
	}
	if (val == 5) {
		if (fitsIn(segBits, solvedSeg[7])) {
			return 3;
		}
		return -1;
	}
	else if (val == 6) {
		if (fitsIn(segBits, solvedSeg[4])) {
			return 9;
		}
		else if (fitsIn(segBits, solvedSeg[7])) {
			return 0;
		}
		return 6;
	}
	std::cout << "Error on decodeEasyStep2! Value: " << val << std::endl;
	return -10;
}

int decodeEasyStep1(std::string& segBits) {
	int val = segBits.size();
	switch (val)
	{
	case 0:
		return -2;
	case 2:
		return 1;
	case 3:
		return 7;
	case 4:
		return 4;
	case 5:
	case 6:
		return -1;
	case 7:
		return 8;
	default:
		break;
	}
	std::cout << "Error on decodeEasy! Value: " << val << std::endl;
	return -10;
}

std::map<int, std::string> decode(std::vector<std::string>& segs) {
	std::map<int, std::string> solved;
	int index = 0;
	for (std::string seg : segs)
	{
		int val = decodeEasyStep1(seg);
		if (val >= 0) {
			solved.emplace(val, seg);
			segs[index] = "";
		}
		index++;
	}
	index = 0;
	for (std::string seg : segs)
	{
		int val = decodeEasyStep2(seg, solved);
		if (val >= 0) {
			solved.emplace(val, seg);
			segs[index] = "";
		}
		index++;
	}
	index = 0;
	for (std::string seg : segs)
	{
		int val = decodeEasyStep3(seg, solved);
		if (val >= 0) {
			solved.emplace(val, seg);
			segs[index] = "";
		}
		index++;
	}
	return solved;
}

void sevenSegmentSearch() {
	std::ifstream inputs("SevenSegmentSearchInputs.txt");
	std::vector<std::string> segs;
	std::map<int, std::string> solvedSegs;
	int sum = 0;
	bool done = false;

	if (inputs.is_open())
	{
		// Read input file to vector
		do {
			segs.clear();
			solvedSegs.clear();
			std::string temp;
			std::string num;
			for (int i = 0; i < 10; i++) {
				temp.clear();
				std::getline(inputs, temp, ' ');
				segs.push_back(temp);
			}
			temp.clear();
			std::getline(inputs, temp, ' ');
			solvedSegs = decode(segs);
			segs.clear();
			for (int i = 0; i < 3; i++) {
				temp.clear();
				std::getline(inputs, temp, ' ');
				segs.push_back(temp);
			}
			temp.clear();
			std::getline(inputs, temp);
			segs.push_back(temp);

			for (std::string seg : segs) {
				int tempNum;
				tempNum = findByValue(solvedSegs, getId(seg));
				num += ((char)tempNum + 48);
			}
			sum += std::stoi(num, nullptr, 10);

		} while (inputs.peek() != EOF);
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	std::cout << sum << std::endl;
}