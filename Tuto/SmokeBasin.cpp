#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool checkNeighbour(std::vector<std::vector<int>> grid, int x, int y) {
	int upperX = x + 1, upperY = y + 1, lowerX = std::abs(x - 1), lowerY = std::abs(y - 1);
	if (x == 99) {
		upperX -= 2;
	}
	if (y == 99) {
		upperY -= 2;
	}
	if (grid[x][y] >= grid[lowerX][y] || grid[x][y] >= grid[upperX][y] || grid[x][y] >= grid[x][upperY] || grid[x][y] >= grid[x][lowerY]) {
		return false;
	}
	else {
		return true;
	}
}

int getBasinSize(std::vector<std::vector<int>> grid, int x, int y) {
	int upperX = x + 1, upperY = y + 1, lowerX = x - 1, lowerY = y - 1, sum = 0;
	if (upperX < 0) {
		upperX + 1;
	}
	if (upperY < 0) {
		upperY + 1;
	}
	if (upperX > 99) {
		upperX - 1;
	}
	if (upperY > 99) {
		upperY - 1;
	}
	if (lowerX < 0) {
		lowerX + 1;
	}
	if (lowerY < 0) {
		lowerY + 1;
	}
	if (lowerX > 99) {
		lowerX - 1;
	}
	if (lowerY > 99) {
		lowerY - 1;
	}
	if (grid[x][y] + 1 == grid[upperX][y]) {
		sum += getBasinSize(grid, upperX, y) + 1;
	}
	if (grid[x][y] + 1 == grid[lowerX][y]) {
		sum += getBasinSize(grid, lowerX, y) + 1;
	}
	if (grid[x][y] + 1 == grid[x][upperY]) {
		sum += getBasinSize(grid, x, upperY) + 1;
	}
	if (grid[x][y] + 1 == grid[x][lowerY]) {
		sum += getBasinSize(grid, x, lowerY) + 1;
	}
	return sum;
}

int getAnswer(std::vector<std::vector<int>> grid, std::vector<std::vector<int>> coords) {
	std::vector<int> sizes;
	for (std::vector<int> iVect : coords) {
		sizes.push_back(getBasinSize(grid, iVect[0], iVect[1]));
	}
	std::sort(sizes.begin(), sizes.end());
	return (*sizes.end()) * (*(sizes.end() - 1)) * (*(sizes.end() - 2));
}

void smokeBasin() {
	std::vector<std::vector<int>> grid;
	std::vector<std::vector<int>> coords;
	std::ifstream inputs("SmokeBasinInputs.txt");
	std::string line;
	int sum = 0;

	while (inputs >> line)
	{
		std::vector<int> temp;
		for (char c : line) {
			temp.push_back(c - '0');
		}
		grid.push_back(temp);
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (checkNeighbour(grid, i, j)) {
				coords.push_back({ i, j });
				sum += grid[i][j] + 1;
			}
		}
	}

	std::cout << sum << std::endl;
	std::cout << getAnswer(grid, coords) << std::endl;
}

// 1260, 1588