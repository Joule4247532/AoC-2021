#include <iostream>
#include <fstream>
#include <string>

struct Submarine
{
	int Depth = 0;
	int Pos = 0;
	int Aim = 0;
};

void dive() {
	// Variables
	std::ifstream inputs("DiveInputs.txt");
	std::string direction;
	Submarine sub;

	if (inputs.is_open())
	{
		// Read input file to vector
		while (inputs >> direction)
		{
			int num;
			if (direction == "forward") {
				inputs >> num;
				sub.Pos += num;
			}
			else if (direction == "up") {
				inputs >> num;
				sub.Depth -= num;
			}
			else if (direction == "down") {
				inputs >> num;
				sub.Depth += num;
			}
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	std::cout << "Part 1: " << sub.Pos << " : " << sub.Depth << " : " << sub.Pos * sub.Depth << std::endl;

	inputs.open("DiveInputs.txt");
	sub.Pos = 0;
	sub.Depth = 0;

	if (inputs.is_open())
	{
		// Read input file to vector
		while (inputs >> direction)
		{
			int num;
			if (direction == "forward") {
				inputs >> num;
				sub.Pos += num;
				sub.Depth += sub.Aim * num;
			}
			else if (direction == "up") {
				inputs >> num;
				sub.Aim -= num;
			}
			else if (direction == "down") {
				inputs >> num;
				sub.Aim += num;
			}
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	std::cout << "Part 2: " << sub.Pos << " : " << sub.Depth << " : " << sub.Aim << " : " << sub.Pos * sub.Depth << std::endl;

}