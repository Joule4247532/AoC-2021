#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<int> findMostCommon(std::vector<std::string> strVec) {
	std::vector<int> gamma(12);
	int counter;
	for (std::string& str : strVec) {
		counter = 0;
		for (char const& c : str) {
			gamma[counter] += (c == '1') ? 1 : -1;
			counter++;
		}
	}

	counter = 0;
	for (int& n : gamma) {
		gamma[counter] = (n > 0) ? 1 : (n == 0) ? -1 : 0;
		counter++;
	}
	return gamma;
}

std::vector<std::string> search(std::vector<std::string> strVec, std::string substr) {
	std::vector<std::string> temp;
	for (std::string& str : strVec) {
		if (str.rfind(substr, 0) == 0) {
			temp.push_back(str);
		}
	}
	return temp;
}

std::string solveA(std::vector<std::string> strVec) {
	std::vector<std::string> temp = strVec;
	std::string searchTerm;
	int mostCommon;
	for (int i = 0; temp.size() != 1; i++) {
		mostCommon = findMostCommon(temp)[i];
		mostCommon = (mostCommon == -1) ? 1 : mostCommon;
		searchTerm.push_back((char)mostCommon + 48);
		temp = search(temp, searchTerm);
	}
	return temp[0];
}

std::string solveB(std::vector<std::string> strVec) {
	std::vector<std::string> temp = strVec;
	std::string searchTerm;
	int mostCommon;
	for (int i = 0; temp.size() != 1; i++) {
		mostCommon = findMostCommon(temp)[i];
		mostCommon = (mostCommon == -1) ? 1 : mostCommon;
		searchTerm.push_back((char)((mostCommon == 1) ? 0 : 1) + 48);
		temp = search(temp, searchTerm);
	}
	return temp[0];
}

void binairyDiagnostic()
{
	// Variables
	std::ifstream inputs("BinaryDiagnostic.txt");
	std::vector<std::string> lines;
	std::string line;
	std::string line2;
	std::vector<int> gamma(12);
	int counter;

	if (inputs.is_open())
	{
		// Read input file to vector
		while (inputs >> line)
		{
			lines.push_back(line);
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	gamma = findMostCommon(lines);

	line.clear();
	counter = 0;
	for (int& n : gamma) {
		line.push_back((char)n + 48);
		line2.push_back((char)((n == 1) ? 0 : 1) + 48);
		counter++;
	}
	int smth = stoi(line, nullptr, 2);
	int smth2 = stoi(line2, nullptr, 2);
	std::cout << smth*smth2 << std::endl;

	int smth3 = stoi(solveA(lines), nullptr, 2);
	int smth4 = stoi(solveB(lines), nullptr, 2);
	std::cout << smth3 * smth4 << std::endl;
}