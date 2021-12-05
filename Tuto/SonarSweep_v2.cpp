#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void sonarSweep2() {
	// Variables
	std::ifstream inputs("SonarSweepInputs.txt");
	std::string filename;
	int num;
	std::vector<int> numbers, buffer;
	int count = 0;

	if (inputs.is_open())
	{
		// Read input file to vector
		while (inputs >> num)
		{
			numbers.push_back(num);
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	// Count the number of times n is bigger then n-1
	for (int& n : numbers)
	{
		if (buffer.size() >= 1)
		{
			if (buffer[0] < n) { count++; }
			buffer.erase(buffer.begin());
		}
		buffer.push_back(n);
	}

	// Print the result
	std::cout << "Part 1: It increases " << count << " times" << std::endl;

	// Reset variables
	count = 0;
	buffer.clear();

	// Count the number of times the sum of n, n+1, n+2 is bigger then the sum of n-1, n, n+1
	// a+b+c < b+c+d == a < d
	for (int& n : numbers)
	{
		buffer.push_back(n);
		if (buffer.size() >= 4)
		{
			if (buffer[0] < buffer[3]) { count++; }
			buffer.erase(buffer.begin());
		}
	}

	// Print the result
	std::cout << "Part 2: It increases " << count << " times" << std::endl;
}