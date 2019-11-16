//Lab 9: Tic Tac Toe
//Author: Kennedy Bowman
//Date: 3/20/14
//Section: 02

//Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Class
class Player {
	public:
		//Member variable
		int iBoardSelection;	
};

//Function prototypes
void ShowBoard (char *);
int CheckSelection (int, char *, Player);
int AIMove(int, char *, Player);
void CheckWinner (char *);

//Global variable declarations and initializations
char cBoard[10] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
char cWon = ' ';

int main(void) {
	Player Human;
	Player AI;
	
	//Variable declarations and initualizations
	int iFirstPlayer;
	int iHumanPlayer;
	int iAIPlayer;
	int iCurrentPlayer;
	
	cout << "Tic Tac Toe" << endl;
	
	//Determining randomly who will start the game
	srand(time(0));
	iFirstPlayer = rand() % 2;
	
	if (iFirstPlayer == 0) {
		cout << "You get to play first (as X)!" << endl;
		iHumanPlayer = 0;
		iAIPlayer = 1;
		iCurrentPlayer = 0;
	}
	else {
		cout << "The computer gets to play first. You will play as O." <<endl;
		iHumanPlayer = 1;
		iAIPlayer = 0;
		iCurrentPlayer = 1;
	}
	
	while (cWon == ' ') {
		//Asks user for selection if it is their turn
		if (iCurrentPlayer == 0) {
			cout << "Enter a square to play (1-9): ";
			cin >> Human.iBoardSelection;
			
			if (CheckSelection(iHumanPlayer, cBoard, Human) == 0) {
				iCurrentPlayer = 1;
				ShowBoard(cBoard);
			}
			else if (CheckSelection(iHumanPlayer, cBoard, Human) == -3) {
				iCurrentPlayer = 0;
			}
		}
		//AI if it is not the user's turn
		else if (iCurrentPlayer == 1) {
			AI.iBoardSelection = rand() % 9;
			
			if (AIMove(iAIPlayer, cBoard, AI) == 0) {
				iCurrentPlayer = 0;
				ShowBoard(cBoard);
			}
			else if (AIMove(iAIPlayer, cBoard, AI) == -3) {
				iCurrentPlayer = 1;
			}
		}
		
		CheckWinner(cBoard);
	}
	
	system ("pause");	
	return 0;
}

void ShowBoard (char *cBoard) {
	cout << "_" << cBoard[0] << "_|_" << cBoard[1] << "_|_" << cBoard[2] << "_" << endl;
	cout << "_" << cBoard[3] << "_|_" << cBoard[4] << "_|_" << cBoard[5] << "_" << endl;
	cout << "_" << cBoard[6] << "_|_" << cBoard[7] << "_|_" << cBoard[8] << "_" << endl;
}

int CheckSelection (int iHumanPlayer, char *cBoard, Player Human) {
	//Checking for entries outside the board border
	if (Human.iBoardSelection < 1 || Human.iBoardSelection > 9) {
		cout << "Invalid square. Please try a number between 1 and 9." << endl;
		return -3;
	}
	else {
		//Places an X if the space is free
		if (cBoard[Human.iBoardSelection - 1] == '_' && iHumanPlayer == 0) {
			cBoard[Human.iBoardSelection - 1] = 'X';
			return 0;
		}
		//Places a Y if the space is free
		else if (cBoard[Human.iBoardSelection - 1] == '_' && iHumanPlayer == 1) {
			cBoard[Human.iBoardSelection - 1] = 'O';
			return 0;
		}
		//Alerts the user if their selection was already taken
		else {
			cout << "That square is already filled." << endl;
			return -3;
		}
	}
}

int AIMove (int iAIPlayer, char *cBoard, Player AI) {
		//Places an X if the space is free
		if (cBoard[AI.iBoardSelection] == '_' && iAIPlayer == 0) {
			cBoard[AI.iBoardSelection] = 'X';
			cout << "AI Move" << endl;
			return 0;
		}
		//Places a Y if the space is free
		else if (cBoard[AI.iBoardSelection] == '_' && iAIPlayer == 1) {
			cBoard[AI.iBoardSelection] = 'O';
			cout << "AI Move" << endl;
			return 0;
		}
		//If the random number generated for iAISelection is already filled
		else {
			return -3;
		}
}

void CheckWinner (char *cBoard) {
	//Determining if there is a winner and who it is
	if (cBoard[0] == 'X' && cBoard[1] == 'X' && cBoard[2] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[3] == 'X' && cBoard[4] == 'X' && cBoard[5] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[6] == 'X' && cBoard[7] == 'X' && cBoard[8] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[0] == 'X' && cBoard[3] == 'X' && cBoard[6] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[1] == 'X' && cBoard[4] == 'X' && cBoard[7] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[2] == 'X' && cBoard[5] == 'X' && cBoard[8] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[0] == 'X' && cBoard[4] == 'X' && cBoard[8] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[2] == 'X' && cBoard[4] == 'X' && cBoard[6] == 'X') {
		cWon = 'X';
	}
	else if (cBoard[0] == 'O' && cBoard[1] == 'O' && cBoard[2] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[3] == 'O' && cBoard[4] == 'O' && cBoard[5] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[6] == 'O' && cBoard[7] == 'O' && cBoard[8] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[0] == 'O' && cBoard[3] == 'O' && cBoard[6] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[1] == 'O' && cBoard[4] == 'O' && cBoard[7] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[2] == 'O' && cBoard[5] == 'O' && cBoard[8] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[0] == 'O' && cBoard[4] == 'O' && cBoard[8] == 'O') {
		cWon = 'O';
	}
	else if (cBoard[2] == 'O' && cBoard[4] == 'O' && cBoard[6] == 'O') {
		cWon = 'O';
	}
	
	//Printing the winner
	if (cWon == 'X') {
		cout << "X is the winner!" << endl;
	}
	else if (cWon == 'O') {
		cout << "O is the winner!" << endl;
	}
	
	//Determining if there is a tie and alerting the user
	int x;
	int iTie = 0;
	
	for (x = 0; x <9; x++ ) {
		if (cBoard[x] != '_') {
			iTie += 1;
		}
	}
	
	if (iTie == 9) {
		cWon = 'T';
		cout << "It's a tie!" << endl;
	}
}
