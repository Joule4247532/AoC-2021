#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int flashCount = 0;

// Well you messed up
void resetFlashed(std::vector<std::vector<int>>& grid) {
	for (std::vector<int>& iVect : grid)
	{
		for (int& n : iVect)
		{
			if (n < 0) { n = 0; }
		}
	}
}

// E
bool exists(int x, int y) {
	if (x < 0) { return false; }
	if (x > 9) { return false; }
	if (y < 0) { return false; }
	if (y > 9) { return false; }
	return true;
}

// Did you watch Nemo?
int flashOctopuses(std::vector<std::vector<int>> points, std::vector<std::vector<int>>& grid) {
	int flashes = 0;
	for (std::vector<int> point : points) {
		flashCount++;
		flashes++;
		grid[point[0]][point[1]] = -1;
		if (exists(point[0] - 1, point[1] - 1)) {
			if (grid[point[0] - 1][point[1] - 1] >= 0) {
				grid[point[0] - 1][point[1] - 1]++;
			}
		}
		if (exists(point[0] - 1, point[1])) {
			if (grid[point[0] - 1][point[1]] >= 0) {
				grid[point[0] - 1][point[1]]++;
			}
		}
		if (exists(point[0] - 1, point[1] + 1)) {
			if (grid[point[0] - 1][point[1] + 1] >= 0) {
				grid[point[0] - 1][point[1] + 1]++;
			}
		}
		if (exists(point[0], point[1] - 1)) {
			if (grid[point[0]][point[1] - 1] >= 0) {
				grid[point[0]][point[1] - 1]++;
			}
		}
		if (exists(point[0], point[1] + 1)) {
			if (grid[point[0]][point[1] + 1] >= 0) {
				grid[point[0]][point[1] + 1]++;
			}
		}
		if (exists(point[0] + 1, point[1] - 1)) {
			if (grid[point[0] + 1][point[1] - 1] >= 0) {
				grid[point[0] + 1][point[1] - 1]++;
			}
		}
		if (exists(point[0] + 1, point[1])) {
			if (grid[point[0] + 1][point[1]] >= 0) {
				grid[point[0] + 1][point[1]]++;
			}
		}
		if (exists(point[0] + 1, point[1] + 1)) {
			if (grid[point[0] + 1][point[1] + 1] >= 0) {
				grid[point[0] + 1][point[1] + 1]++;
			}
		}
	}
	return flashes;
}

// I know how to count :  1, 3, 4, 7, 9?, 10!
std::vector<std::vector<int>> getTenAndAbove(std::vector<std::vector<int>>& grid) {
	std::vector<std::vector<int>> OctoToFlash;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] > 9) {
				OctoToFlash.push_back({ i, j });
			}
		}
	}
	return OctoToFlash;
}

// Damnit, Barry...
int doFlash(std::vector<std::vector<int>>& grid) {
	int flashSum = 0;
	std::vector<std::vector<int>> toFlash = getTenAndAbove(grid);
	while (toFlash.size() != 0) {
		flashSum += flashOctopuses(toFlash, grid);
		toFlash = getTenAndAbove(grid);
	}
	resetFlashed(grid);
	return flashSum;
}

// IT'S OVER 9000!!!!!!!!!!
void increaseLevels(std::vector<std::vector<int>>& grid) {
	for (std::vector<int>& iVect : grid)
	{
		for (int& n : iVect)
		{
			n++;
		}
	}
}

// no step on snek
bool step(std::vector<std::vector<int>>& grid) {
	increaseLevels(grid);
	int numOfFlashes = doFlash(grid);
	if (numOfFlashes == 100) {
		return true;
	}
	else {
		return false;
	}
}

void dumboOctopus() {
	std::ifstream inputs("DumboOctopusInputs.txt");
	std::vector<std::vector<int>> grid;
	int num = 0;

	if (inputs.is_open())
	{
		for (int i = 0; i < 10; i++) {
			std::vector<int> temp;
			for (int j = 0; j < 10; j++) {
				inputs >> num;
				temp.push_back(num);
			}
			grid.push_back(temp);
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	for (int i = 0; i < 1000; i++) {
		if (step(grid)) {
			std::cout << "Step : " << i + 1 << std::endl;
			break;
		}
		if (i == 99) {
			std::cout << flashCount << std::endl;
		}
	}
	
}
// 1546