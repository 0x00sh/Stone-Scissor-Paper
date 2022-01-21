/* MIT License

Copyright (c) 2022 Alexandr Katrenko

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include <iostream>

const int C_STONE = 1;
const int C_SCISSOR = 2;
const int C_PAPER = 3;

const int C_TIE = 0;
const int C_WIN_PLAYER = 1;
const int C_WIN_COMPUTER = 2;

int scorePlayer, scoreComputer;

void winner(int statusWin) {
	switch(statusWin) {
		case C_TIE:
			std::cout << "Tie!\n\n";
			break;
		case C_WIN_PLAYER:
			std::cout << "You win!\n\n";
			scorePlayer += 1;
			break;
		case C_WIN_COMPUTER:
			std::cout << "You lose!\n\n";
			scoreComputer += 1;
			break;
	}

	std::cout << "Score: " << scorePlayer << ":" << scoreComputer << std::endl;
}

void analize(int playerChoice, int computerChoice) {
	if (playerChoice == computerChoice) {
		winner(C_TIE);
	} else if (playerChoice == C_STONE && computerChoice == C_SCISSOR) {
		winner(C_WIN_PLAYER);
	} else if (playerChoice == C_SCISSOR && computerChoice == C_STONE) {
		winner(C_WIN_COMPUTER);
	} else if (playerChoice == C_STONE && computerChoice == C_PAPER) {
		winner(C_WIN_COMPUTER);
	} else if (playerChoice == C_PAPER && computerChoice == C_STONE) {
		winner(C_WIN_PLAYER);
	} else if (playerChoice == C_PAPER && computerChoice == C_SCISSOR) {
		winner(C_WIN_COMPUTER);
	} else if (playerChoice == C_SCISSOR && computerChoice == C_PAPER) {
		winner(C_WIN_PLAYER);
	}
}

void choice() {
	int playerChoice, computerChoice, choice;
	std::cout << "Choose Stone(1), Scissor(2) or Paper(3): "; std::cin >> choice;
	
	switch(choice) {
		case C_STONE:
			playerChoice = C_STONE;
			std::cout << "You choose Stone\n";
			break;
		case C_SCISSOR:
			playerChoice = C_SCISSOR;
			std::cout << "You choose Scissor\n";
			break;
		case C_PAPER:
			playerChoice = C_PAPER;
			std::cout << "You choose Paper\n";
			break;
	}

	computerChoice = rand() %3 +1;

	switch(computerChoice) {
		case C_STONE:
			std::cout << "Computer choose Stone\n";
			break;
		case C_SCISSOR:
			std::cout << "Computer choose Scissor\n";
			break;
		case C_PAPER:
			std::cout << "Computer choose Paper\n";
			break;
	}

	analize(playerChoice, computerChoice);
}

int main() {
	std::cout << "WELCOME!\n\n";
	do {		
		choice();	
	} while(true);
	 
	return 0;
}
