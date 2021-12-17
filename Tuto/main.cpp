#include <iostream>

#include "SonarSweep_v2.hpp"
#include "Dive.hpp"
#include "BinairyDiagnostic.hpp"
#include "GiantSquid.hpp"
#include "HydrothermalVenture.hpp"
#include "Lanternfish.hpp"
#include "TheTreacheryOfWhales.hpp"
#include "SevenSegmentSearchInputs.hpp"
#include "SyntaxScoring.hpp"
#include "SmokeBasin.hpp"
#include "DumboOctopus.hpp"
#include "TransparentOrigami.hpp"
#include "PacketDecoder.hpp"

int prompt() {
	std::cout << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "[1] SonarSweep" << std::endl;
	std::cout << "[2] Dive!" << std::endl;
	std::cout << "[3] Binairy Diagnostic" << std::endl;
	std::cout << "[4] Giant Squid" << std::endl;
	std::cout << "[5] Hydrothermal Venture" << std::endl;
	std::cout << "[6] Lanternfish" << std::endl;
	std::cout << "[7] The Treachery Of Whales" << std::endl;
	std::cout << "[8] Seven Segment Search" << std::endl;
	std::cout << "[9] Smoke Basin" << std::endl;
	std::cout << "[10] Syntax Scoring" << std::endl;
	std::cout << "[11] Dumbo Octopus" << std::endl;
	std::cout << "[13] Transparent Origami" << std::endl;
	std::cout << "[16] Packet Decoder" << std::endl;
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
		case 7:
			theTreacheryOfWhales();
			break;
		case 8:
			sevenSegmentSearch();
			break;
		case 9:
			smokeBasin();
			break;
		case 10:
			syntaxScoring();
			break;
		case 11:
			dumboOctopus();
			break;
		case 13:
			transparentOrigami();
			break;
		case 16:
			packetDecoder();
			break;
		default:
			break;
		}
	} while (option != -1);
}