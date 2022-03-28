#include <vector>
#include <stdlib.h>
#include <iostream>

char turn{ 'X' };
int position{ 0 };
int count { 0 };

void greetings();
void drawBoard(const std::vector < char > &board);
void updateBoard(std::vector < char > &board, char &turn); 
bool gameOver(const std::vector < char > &board);

int main() {
	std::vector < char > board {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9'
	};

	do {
		system("cls");
		greetings();
		drawBoard(board);
		updateBoard(board, turn);
		++count;
	} while (count < 9 && gameOver(board));

	greetings();
	system("cls");
	drawBoard(board);
	
	if (count == 9) {
		std::cout << "Game Draw!";
	}
	else if (turn == 'X') {
		std::cout << "Player 1 [X] Won the Game!";
	}
	else {
		std::cout << "Player 2 [O] Won the Game!";
	}

	return 0;
}

void greetings() {
	std::cout << "TIC-TAC-TOE GAME FOR 2 PLAYERS!" << '\n';
	std::cout << "  Player 1 [X] - Player 2 [O]" << '\n';
}

void drawBoard(const std::vector < char > &board) {
	std::cout << '\n';
	std::cout << '\t' << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << '\n';
	std::cout << '\t' << "-----------------" << '\n';
	std::cout << '\t' << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n';
	std::cout << '\t' << "-----------------" << '\n';
	std::cout << '\t' << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << '\n';
	std::cout << '\n';
}

void updateBoard(std::vector < char > &board, char &turn) {
	Turn:
	if (turn == 'X') {
		std::cout << "Player 1 [X] Turn: ";
		std::cin >> position;
	}
	else if (turn == 'O') {
		std::cout << "Player 2 [O] Turn: ";
		std::cin >> position;
	}
	
	if (position < 1 || position > 9) {
		std::cout << "Invalid Placement! Try Again!" << '\n';
		goto Turn;
	}

	if (board[position - 1] == 'X' || board[position - 1] == 'O') {
		std::cout << "Invalid Placement! Try Again!" << '\n';
		goto Turn;
	}
   	else if (board[position - 1] != 'X' || board[position - 1] != 'O') {
		board[position - 1] = turn;
	}
	
	if (gameOver(board)) {
		if (turn == 'X')
			turn = 'O';
		else if (turn == 'O')
			turn = 'X';	
	}	
}

bool gameOver(const std::vector < char > &board) {	
	// check horizontal rows
	if (board[0] == board[1] && board[1] == board[2] ||
		board[3] == board[4] && board[4] == board[5] || 
		board[6] == board[7] && board[7] == board[8])
		return false;

	// check vertical rows
	if (board[0] == board[3] && board[3] == board[6] ||
		board[1] == board[4] && board[4] == board[7] ||
		board[2] == board[5] && board[5] == board[8])
		return false;

	// check diagonals
	if (board[0] == board[4] && board[4] == board[8] ||
		board[2] == board[4] && board[4] == board[6])
		return false;

	return true;	
}
