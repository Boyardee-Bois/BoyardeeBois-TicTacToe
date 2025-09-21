/*
Boyardee Bois - TicTacToe

Authors: Joshua Klenk, Joshua Lynch, Erwin Jonson,
		 Damian Mercedes, Daniel Brooksbank

Date: 9.12.25
Version 2.2
*/

#include <iostream>
#include <limits>
#include <cstdio>
#include <string>

using namespace std;

// making the board into a 2D array with a grid style to replace digits easily -JoshL
char board[3][3] =
{
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

void PrintInstructions()
{
	cout << "\nHow to play:\n"
		<< "- Enter a single number (1 - 9) to place your mark.\n"
		<< "- Only ONE value per line is allowed (ie. `5`).\n"
		<< "- Type 'h' to see these instructions again.\n"
		<< "\nBoard mapping:\n"
		<< " 1 | 2 | 3 \n"
		<< "---+---+---\n"
		<< " 4 | 5 | 6 \n"
		<< "---+---+---\n"
		<< " 7 | 8 | 9 \n\n"
		<< "######################################################\n";
}

void TicTacToeBoard() //Had to remove a lot of the #'s because it made screen cluttered
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n"
		<< "---+---+---\n"
		<< " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n"
		<< "---+---+---\n"
		<< " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n"
		<< " \n"
		<< " \n";
	cout << "#########################################################" << endl;
}

char checkWinner3by3(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return board[i][0];
	}

	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return board[0][i];
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[0][2];
	}

	return ' ';
}

bool getPlayerMove(char currentPlayer)
{
	int choice;

	while (true)
	{
		cin >> ws;

		int next = cin.peek();

		//Skip spaces & tabs
		while (next == ' ' || next == '\t') { cin.get(); next = cin.peek(); }

		//Check if h for help was entered
		if (next == 'h' || next == 'H')
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			PrintInstructions();

			TicTacToeBoard();

			cout << "Enter your choice (1-9) or 'h' for help: ";

			continue;
		}

		// Handles invalid input 
		if (!(cin >> choice))
		{

			cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << endl;

			TicTacToeBoard();

			cout << "Invalid input. Enter your choice (1-9) or 'h' for help: \n" << endl;

			continue;
		}

		next = cin.peek();

		//Skip spaces & tabs
		while (next == ' ' || next == '\t') { cin.get(); next = cin.peek(); }

		//Re-prompt
		if (next != '\n' && next != '\r' && next != EOF)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input. Enter your choice (1-9) or 'h' for help: \n";

			TicTacToeBoard();

			continue;
		}

		if ((choice < 1 || choice > 9))
		{
			cout << endl;

			TicTacToeBoard();

			cout << "Invalid input. Enter your choice (1-9) or 'h' for help: \n" << endl;

			continue;
		}

		int row = (choice - 1) / 3;
		int col = (choice - 1) % 3;

		if (board[row][col] == 'X' || board[row][col] == 'O' || board[row][col] == 'x' || board[row][col] == 'o')
		{
			cout << "This space is taken! Choose another or 'h' for help: " << endl;

			TicTacToeBoard();

			continue;
		}

		board[(choice - 1) / 3][(choice - 1) % 3] = currentPlayer;

		return true;
	}
}

/*
* @brief Prompts the user to play again and validates their input.
* 
* This function displays a play again prompt and reads a single line of
* user input. It handles various forms of invalid input such as a single
* character, multiple characters, an empty line, or the End of File signal (Ctr+Z).
* The function continuously loops until a valid 'Y' or 'N' response is received.
*
* @param None.
* @return Returns true if the user chooses to play again ('Y' or 'y').
* @return Returns false if the user chooses not to play again ('N' or 'n').
*/
bool playAgainPrompt()
{
	while (true)
	{
		cout << "\nDo you want to play again? (Y/N): ";

		string response;

		getline(cin >> ws, response);

		if (cin.eof())
		{
			cin.clear();

			cout << "\nInvalid input. Please enter Y or N.\n";

			continue;
		}

		if (cin.fail())
		{
			cin.clear();

			cout << "\nInvalid input. Please enter Y or N.\n";

			continue;
		}

		if (response.length() == 1)
		{
			char choice = response[0];

			if (choice == 'Y' || choice == 'y')
			{
				return true;
			}

			if (choice == 'N' || choice == 'n')
			{
				cout << "\nGood-Bye!\n";

				return false;
			}
		}

		cout << "\nInvalid input. Please enter Y or N.\n";
	}
}


int main()
{
	do
	{
		system("cls");

		cout << "\n##### Welcome to Boyardee Bois' Tic Tac Toe! ######\n\n" << endl;

		// Resets board at the start of each game
		char blankSpace = ' ';

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = blankSpace;
			}
		}

		char player1, player2;

		cout << "Player 1, choose your marker (X/O): ";

		cin >> player1;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		while (player1 != 'X' && player1 != 'x' && player1 != 'O' && player1 != 'o')
		{
			cout << "Invalid input" << endl;

			cout << "Player 1, choose your marker (X/O): " << endl;

			if (!(cin >> player1))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (player1 == 'X' || player1 == 'x')
		{
			player1 = 'X';
			player2 = 'O';

		}
		else
		{
			player1 = 'O';
			player2 = 'X';

		}

		char players[3];
		players[1] = player1;
		players[2] = player2;

		int currentPlayerNum = 1;

		// Main game loop (max 9 turns)
		for (int turn = 0; turn < 9; turn++)
		{
			TicTacToeBoard();

			cout << "\n\n";

			char currentPlayer = players[currentPlayerNum];

			cout << "Player " << currentPlayerNum << " (" << currentPlayer
				<< "), enter your choice (1-9) or 'h' for help: ";

			while (!getPlayerMove(currentPlayer))
			{
				cout << "Player " << currentPlayerNum << " (" << currentPlayer
					<< "), try again: ";
			}

			// Check for a winner
			char winner = checkWinner3by3(board);

			if (winner == 'X' || winner == 'O')
			{
				TicTacToeBoard();
				cout << "Player " << currentPlayerNum << " (" << winner << ") wins!\n";
				break;
			}

			currentPlayerNum = 3 - currentPlayerNum;

			// Draw if all 9 turns are used
			if (turn == 8) {
				TicTacToeBoard();
				cout << "It's a draw!\n";
			}
		}

	} while (playAgainPrompt());

	return 0;
}
