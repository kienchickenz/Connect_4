#include <iostream>
#include <vector>
#include <string>
#include "Connect_4.hpp"

int player = 1;
int user_choice;
std::vector<std::vector<std::string> > board = { {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "} };
int a = 0;

// Introduction
void introduction() {

	std::cout << "==================== CONNECT 5 ====================\n";
	
	std::cout << "Welcome to the game,\n";	
	std::cout << ">> Player 1 : x <<\n";
	std::cout << ">> Player 2 : o <<\n\n";

	std::cout << "Here is a 10x10 grid:\n";

	draw_board();

}

// Check for the winner
bool is_winner() {

	bool win = false;

	// Check horizontal spaces
	for(int row = 0; row <= 9; row++) {

		for (int col = 0; col <= 9; col++) {

			if(board[row][col] != " " && board[row][col + 1] == board[row][col] && board[row][col + 2] == board[row][col] && board[row][col + 3] == board[row][col] && board[row][col + 4] == board[row][col]) {

				win = true;

			}

		}

	}

	// Check vertical spaces
	for(int row = 0; row <= 5; row++) {

		for(int col = 0; col <= 9; col++) {

			if(board[row][col] != " " && board[row + 1][col] == board[row][col] && board[row + 2][col] == board[row][col] && board[row + 3][col] == board[row][col] && board[row + 4][col] == board[row][col]) {

				win = true;

			}
		
		}

	}

	// Check / diagonal spaces
	for(int row = 0; row <= 5; row++) {
	
		for(int col = 0; col <= 5; col++) {
	
			if(board[row][col] != " " && board[row + 1][col + 1] == board[row][col] && board[row + 2][col + 2] == board[row][col] && board[row + 3][col + 3] == board[row][col] && board[row + 4][col + 4] == board[row][col]) {            
	
				win = true;

			}
		
		}

	}

	// Check \ diagonal spaces
	for(int row = 4; row <= 9; row++) {

		for(int col = 0; col <= 5; col++) {

			if(board[row][col] != " " && board[row - 1][col + 1] == board[row][col] && board[row - 2][col + 2] == board[row][col] && board[row - 3][col + 3] == board[row][col] && board[row - 4][col + 4] == board[row][col]) {

				win = true;

			}

		}

	}

	return win;

}

// Check whether the board is filled up
bool is_tie() {

	bool is_filled_up = true;

	for(int row = 0; row <= 9; row++) {

		for(int col = 0; col <= 9; col++) {

			if(board[row][col] == " ") {

				is_filled_up = false;

			}

		}

	}

	return is_filled_up;

}

// Ask the user for the column
void set_position() {

	std::cout << "PLayer " << player << "'s turn (Enter 0 - 9): \n";
	std::cin >> user_choice;

}

// Fill at the bottom of the selected column
void update_board() {

	for(int row = 9; row >= 0; row--) {

		if( board[row][user_choice] == " " ) {

			if(player % 2 != 0) {

				board[row][user_choice] = "x";
				break;

			} else {

				board[row][user_choice] = "o";
				break;

			}

		}

	}

}

// To change player
void change_player() {

	if(player % 2 != 0) {

		player ++;

	} else {

		player--;

	}

}

// Create the board (Using loop because the size is large)
void draw_board() {

	// Header
	for(int i = 0; i <= 9; i++) {

		std::cout << "  " << i << "   ";

	}

	std::cout << "\n";

	for(int j = 0; j <= 9; j++) {

		std::cout << "-----+";

	}

	std::cout << "\n";

	// Rows with item
	std::string row_with_item;

	for(int row = 0; row <= 9; row++) {

		for(int col = 0; col <= 9; col ++) {

			if(col == 0) {

				row_with_item = "  " + board[row][col] + "  ";  

			} else if(col == 9) {

				row_with_item += "|  " + board[row][col] + "  |";

			} else {

				row_with_item += "|  " + board[row][col] + "  ";

			}

		}

		std::cout << row_with_item;
		std::cout << "\n";

		for(int k = 0; k <= 9; k++) {

			std::cout << "-----+";

		}

		std::cout << "\n";

	}

}

void take_turn() {

	while( !is_winner() && !is_tie() ) {

		set_position();

		update_board();

		change_player();

		draw_board();

	}

}

void end_game() {

	if( is_winner() ) {

		std::cout << "Cogratulations! You won the game.\n";

	} else if( is_tie() ) {

		std::cout << "Oops, the game is a tie.\n";

	}

}
