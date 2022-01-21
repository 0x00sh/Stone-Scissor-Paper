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
