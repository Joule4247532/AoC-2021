#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void lanternfish() {
	std::vector<int> input = { 2,5,2,3,5,3,5,5,4,2,1,5,5,5,5,1,2,5,1,1,1,1,1,5,5,1,5,4,3,3,1,2,4,2,4,5,4,5,5,5,4,4,1,3,5,1,2,2,4,2,1,1,2,1,1,4,2,1,2,1,2,1,3,3,3,5,1,1,1,3,4,4,1,3,1,5,5,1,5,3,1,5,2,2,2,2,1,1,1,1,3,3,3,1,4,3,5,3,5,5,1,4,4,2,5,1,5,5,4,5,5,1,5,4,4,1,3,4,1,2,3,2,5,1,3,1,5,5,2,2,2,1,3,3,1,1,1,4,2,5,1,2,4,4,2,5,1,1,3,5,4,2,1,2,5,4,1,5,5,2,4,3,5,2,4,1,4,3,5,5,3,1,5,1,3,5,1,1,1,4,2,4,4,1,1,1,1,1,3,4,5,2,3,4,5,1,4,1,2,3,4,2,1,4,4,2,1,5,3,4,1,1,2,2,1,5,5,2,5,1,4,4,2,1,3,1,5,5,1,4,2,2,1,1,1,5,1,3,4,1,3,3,5,3,5,5,3,1,4,4,1,1,1,3,3,2,3,1,1,1,5,4,2,5,3,5,4,4,5,2,3,2,5,2,1,1,1,2,1,5,3,5,1,4,1,2,1,5,3,5,2,1,3,1,2,4,5,3,4,3 };
	std::vector<std::vector<long long>> lanternfishs;
	for (int i = 0; i < 80; i++) {
		std::vector<long long> temp = { 0, 8 };
		for (int& n : input) {
			if (n == 0) {
				n = 6;
				temp[0]++;
			}
			else {
				n--;
			}
		}
		for (int j = 0; j < lanternfishs.size(); j++) {
			if (lanternfishs[j][1] == 0) {
				lanternfishs[j][1] = 6;
				temp[0] += lanternfishs[j][0];
			}
			else {
				lanternfishs[j][1]--;
			}
		}
		lanternfishs.push_back(temp);
	}

	long long sum = 0;
	sum += input.size();
	for (std::vector<long long>& iVect : lanternfishs) {
		sum += iVect[0];
	}

	std::cout << sum << std::endl;
}