#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

char flipChar(char c) {
	if (c == ')') {
		return '(';
	}
	else if (c == '}') {
		return '{';
	}
	else if (c == ']') {
		return '[';
	}
	else if (c == '>') {
		return '<';
	}
	else if (c == '(') {
		return ')';
	}
	else if (c == '{') {
		return '}';
	}
	else if (c == '[') {
		return ']';
	}
	else if (c == '<') {
		return '>';
	}
	else {
		std::cout << "Error on flipChar: " << c << std::endl;
		exit(-1);
	}
}

int score(std::vector<char> badChars) {
	int sum = 0;
	for (char c : badChars) {
		if (c == ')') {
			sum += 3;
		}
		else if (c == ']') {
			sum += 57;
		}
		else if (c == '}') {
			sum += 1197;
		}
		else if (c == '>') {
			sum += 25137;
		}
		else {
			std::cout << "Error on score: " << c << std::endl;
			exit(-2);
		}
	}
	return sum;
}

long long scoreIncomplete(std::vector<char> completionStack) {
	long long score = 0;
	while (completionStack.size() > 0)
	{
		char c = completionStack[completionStack.size() - 1];
		completionStack.pop_back();
		score *= 5;
		if (c == '(') {
			score += 1;
		}
		else if (c == '[') {
			score += 2;
		}
		else if (c == '{') {
			score += 3;
		}
		else if (c == '<') {
			score += 4;
		}
		else {
			std::cout << "Error on score: " << c << std::endl;
			exit(-2);
		}
	}
	return score;
}

void syntaxScoring() {
	std::ifstream inputs("SyntaxScoring.txt");
	std::string line;
	std::vector<char> stack;
	std::vector<char> firstBadChar;
	std::vector<long long> scores;

	while (inputs >> line)
	{
		bool incomplete = true;
		for (char c : line) {
			if (c == '(' || c == '{' || c == '[' || c == '<') {
				stack.push_back(c);
			}
			else {
				if (stack[stack.size() - 1] == flipChar(c)) {
					stack.pop_back();
				}
				else {
					firstBadChar.push_back(c);
					incomplete = false;
					break;
				}
			}
		}
		if (incomplete) {
			scores.push_back(scoreIncomplete(stack));
		}
		stack.clear();
	}
	std::cout << score(firstBadChar) << std::endl;
	std::sort(scores.begin(), scores.end());
	std::cout << scores[std::ceil((scores.size() - 1)/2)] << std::endl;
}