#include <iostream>

#include "SonarSweep.h"

void sonarSweep() {
	int count = 0;
	int buffer1 = 0;
	int buffer2 = 0;
	int buffer3 = 0;
	int prevSum = 0;

	char input[20];
 	std::cout << "Sonar Sweep Part 1: Type in the numbers: " << std::endl;
	for (std::cin.getline(input, 20); input[0] != '\0'; std::cin.getline(input, 20)) {
		if (buffer1 == 0) {
			buffer1 = atoi(input);
		}
		else {
			if (buffer1 < atoi(input)) {
				count++;
			}
			buffer1 = atoi(input);
		}
	}
	std::cout << "It increases " << count << " times" << std::endl;


	count = 0;
	buffer1 = 0;

	std::cout << "Sonar Sweep Part 2: Type in the numbers: " << std::endl;
	for (std::cin.getline(input, 20); input[0] != '\0'; std::cin.getline(input, 20)) {
		if (buffer1 == 0) {
			buffer1 = atoi(input);
			if (buffer2 != 0 && buffer3 != 0) {
				if (prevSum < buffer1 + buffer2 + buffer3) {
					count++;
				}
				prevSum = buffer1 + buffer2 + buffer3;
				buffer2 = 0;
			}
		}
		else if (buffer2 == 0) {
			buffer2 = atoi(input);
			if (buffer1 != 0 && buffer3 != 0) {
				if (prevSum < buffer1 + buffer2 + buffer3) {
					count++;
				}
				prevSum = buffer1 + buffer2 + buffer3;
				buffer3 = 0;
			}
		}
		else if (buffer3 == 0) {
			buffer3 = atoi(input);
			if (buffer1 != 0 && buffer2 != 0) {
				if (prevSum != 0) {
					if (prevSum < buffer1 + buffer2 + buffer3) {
						count++;
					}
				}
				prevSum = buffer1 + buffer2 + buffer3;
				buffer1 = 0;
			}
		}
	}
	std::cout << "It increases " << count << " times" << std::endl;
}