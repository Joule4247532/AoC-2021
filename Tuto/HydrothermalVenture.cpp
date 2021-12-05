#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class HydroventsMadness
{
private:
	std::vector<std::vector<int>> m_grid;
public:
	HydroventsMadness()
	{
		std::vector<int> temp;
		for (int j = 0; j < 1000; j++) {
			temp.push_back(0);
		}
		for (int i = 0; i < 1000; i++) {
			this->m_grid.push_back(temp);
		}
	}

	void lineAt(int& x0, int& y0, int& x1, int& y1) {
		if (x0 != x1 && y0 != y1)
			return;
		
		if (x0 == x1) {
			if (y0 <= y1) {
				for (int i = y0; i <= y1; i++) {
					this->m_grid[x0][i]++;
				}
			} 
			else {
				for (int i = y1; i <= y0; i++) {
					this->m_grid[x0][i]++;
				}
			}
		}
		else {
			if (x0 <= x1) {
				for (int i = x0; i <= x1; i++) {
					this->m_grid[i][y0]++;
				}
			}
			else {
				for (int i = x1; i <= x0; i++) {
					this->m_grid[i][y0]++;
				}
			}
		}
	}

	void diagLineAt(int& x0, int& y0, int& x1, int& y1) {
		if (std::abs(x0 - x1) != std::abs(y0 - y1) || (x0 == y0 == x1 == y1))
			return;

		if (x0 - x1 >= 0) {
			if (y0 - y1 >= 0) {
				for (int i = 0; i <= std::abs(x0 - x1); i++) {
					this->m_grid[x0 - i][y0 - i]++;
				}
			}
			else {
				for (int i = 0; i <= std::abs(x0 - x1); i++) {
					this->m_grid[x0 - i][y0 + i]++;
				}
			}
		}
		else {
			if (y0 - y1 >= 0) {
				for (int i = 0; i <= std::abs(x0 - x1); i++) {
					this->m_grid[x0 + i][y0 - i]++;
				}
			}
			else {
				for (int i = 0; i <= std::abs(x0 - x1); i++) {
					this->m_grid[x0 + i][y0 + i]++;
				}
			}
		}
	}

	int countDanger() {
		int temp = 0;
		for (std::vector<int> iVect : this->m_grid) {
			for (int n : iVect) {
				if (n > 1)
					temp++;
			}
		}
		return temp;
	}

private:

};

typedef struct lineSeg {
	int x0, y0, x1, y1;
} lineSeg;

void hydrothermalVenture() {
	std::ifstream inputs("HydrothermalVentureInputs.txt");
	HydroventsMadness HM;
	int val;

	if (inputs.is_open())
	{
		int count = 0;
		lineSeg seg;
		// Read input file to vector
		while (inputs >> val)
		{
			switch (count)
			{
			case 0:
				seg.x0 = val;
				break;
			case 1:
				seg.y0 = val;
				break;
			case 2:
				seg.x1 = val;
				break;
			case 3:
				seg.y1 = val;
				HM.lineAt(seg.x0, seg.y0, seg.x1, seg.y1);
				break;
			default:
				break;
			}
			count++;
			count %= 4;
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	std::cout << HM.countDanger() << std::endl;
	inputs.open("HydrothermalVentureInputs.txt");

	if (inputs.is_open())
	{
		int count = 0;
		lineSeg seg;
		// Read input file to vector
		while (inputs >> val)
		{
			switch (count)
			{
			case 0:
				seg.x0 = val;
				break;
			case 1:
				seg.y0 = val;
				break;
			case 2:
				seg.x1 = val;
				break;
			case 3:
				seg.y1 = val;
				HM.diagLineAt(seg.x0, seg.y0, seg.x1, seg.y1);
				break;
			default:
				break;
			}
			count++;
			count %= 4;
		}
		// Close back the file
		inputs.close();
	}
	else {
		std::cout << "Unable to open file twice" << std::endl;
		return;
	}

	std::cout << HM.countDanger() << std::endl;
}