#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/*
* x=5
#.##.|#..#.
#...#|.....
.....|#...#
#...#|.....
.#.#.|#.###
.....|.....
.....|.....

*/

int flipValue(int flipAxis, int value) {
	if (value <= flipAxis)
		return value;
	return (2 * flipAxis) - value;
}

void applyFlip(std::vector<int>& point, int flip) {
	// flip < 0 : flip on y, flip > 0 : flip on x
	if (flip < 0) {
		point[1] = flipValue(std::abs(flip), point[1]);
	}
	else {
		point[0] = flipValue(std::abs(flip), point[0]);
	}
}

int countPoints(std::vector<std::vector<int>>& points) {
	std::vector<std::vector<int>> checkingStack;
	int count = 0;
	for (std::vector<int> point : points) {
		if (std::find(checkingStack.begin(), checkingStack.end(), point) != checkingStack.end())
			continue;
		count++;
		checkingStack.push_back(point);
	}
	return count;
}

void printGrid(std::vector<std::vector<int>> points) {
	int grid[41][10] = {1};
	std::vector<std::vector<int>> checkingStack;
	for (std::vector<int> point : points) {
		if (std::find(checkingStack.begin(), checkingStack.end(), point) != checkingStack.end())
			continue;
		grid[point[0]][point[1]] = 8;
		checkingStack.push_back(point);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 41; j++) {
			std::cout << grid[j][i];
		}
		std::cout << std::endl;
	}
}

void transparentOrigami() {
	std::ifstream inputs("TransparentOrigamiInputs.txt");
	std::string line;
	std::vector<std::vector<int>> points;

	while (inputs >> line)
	{
		if (line.find('=') == std::string::npos) {
			int secondNum;
			inputs >> secondNum;
			points.push_back({ std::stoi(line), secondNum });
		}
		else {
			if (line.find('y') == std::string::npos) {
				int flipVal;
				inputs >> flipVal;
				for (std::vector<int>& point : points) {
					applyFlip(point, flipVal);
				}
			}
			else {
				int flipVal;
				inputs >> flipVal;
				for (std::vector<int>& point : points) {
					applyFlip(point, -flipVal);
				}
			}
			std::cout << countPoints(points) << std::endl;
		}
	}
	printGrid(points);
}