#include <iostream>

#include "SonarSweep_v2.h"
#include "Dive.h"
#include "BinairyDiagnostic.h"
#include "GiantSquid.h"
#include "HydrothermalVenture.h"
#include "Lanternfish.h"

int prompt() {
	std::cout << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "[1] SonarSweep" << std::endl;
	std::cout << "[2] Dive!" << std::endl;
	std::cout << "[3] Binairy Diagnostic" << std::endl;
	std::cout << "[4] Giant Squid" << std::endl;
	std::cout << "[5] Hydrothermal Venture" << std::endl;
	std::cout << "[6] Lanternfish" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "Type in the number of the challenge (q to quit): ";
	char option[5];
	std::cin.getline(option, 5);
	std::cout << std::endl;
	if (option[0] == 'q')
	{
		return -1;
	}
	else {
		return (int)strtol(option, NULL, 10);
	}
}

int main() {
	std::cout << "Welcome to the AoC-2021 solver by SparkyJoule!" << std::endl;
	int option = 0;
	do {
		option = prompt();
		switch (option)
		{
		case 1:
			sonarSweep2();
			break;
		case 2:
			dive();
			break;
		case 3:
			binairyDiagnostic();
			break;
		case 4:
			giantSquid();
			break;
		case 5:
			hydrothermalVenture();
			break;
		case 6:
			lanternfish();
			break;
		default:
			break;
		}
	} while (option != -1);
}