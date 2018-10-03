#include "library.h"

char tictac[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

void drawBoard()
{
	cout << endl << "    A   B   C " << endl;
	cout << "1:  " << tictac[0][0] << " | " << tictac[0][1] << " | " << tictac[0][2] << " " << endl;
	cout << "   ---|---|---" << endl;
	cout << "2:  " << tictac[1][0] << " | " << tictac[1][1] << " | " << tictac[1][2] << " " << endl;
	cout << "   ---|---|---" << endl;
	cout << "3:  " << tictac[2][0] << " | " << tictac[2][1] << " | " << tictac[2][2] << " " << endl << endl;
}
void makeMove(const int row, const char col, const char player)
{
	if (row == 1 && (col == 'a' || col == 'A'))
		tictac[0][0] = player;
	else if (row == 1 && (col == 'b' || col == 'B'))
		tictac[0][1] = player;
	else if (row == 1 && (col == 'c' || col == 'C'))
		tictac[0][2] = player;
	else if (row == 2 && (col == 'a' || col == 'A'))
		tictac[1][0] = player;
	else if (row == 2 && (col == 'b' || col == 'B'))
		tictac[1][1] = player;
	else if (row == 2 && (col == 'c' || col == 'C'))
		tictac[1][2] = player;
	else if (row == 3 && (col == 'a' || col == 'A'))
		tictac[2][0] = player;
	else if (row == 3 && (col == 'b' || col == 'B'))
		tictac[2][1] = player;
	else if (row == 3 && (col == 'c' || col == 'C'))
		tictac[2][2] = player;
}
bool checkMove(const int row, const char col)
{
	if (col == 'a' || col == 'A' || col == 'b' || col == 'B' || col == 'c' || col == 'C')
	{
		if (row == 1 && (col == 'a' || col == 'A')) {
			if (tictac[0][0] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 1 && (col == 'b' || col == 'B')) {
			if (tictac[0][1] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 1 && (col == 'c' || col == 'C')) {
			if (tictac[0][2] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 2 && (col == 'a' || col == 'A')) {
			if (tictac[1][0] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 2 && (col == 'b' || col == 'B')) {
			if (tictac[1][1] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 2 && (col == 'c' || col == 'C')) {
			if (tictac[1][2] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 3 && (col == 'a' || col == 'A')) {
			if (tictac[2][0] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 3 && (col == 'b' || col == 'B')) {
			if (tictac[2][1] != ' ')
				return true; 
			else
				return false;
		}
		else if (row == 3 && (col == 'c' || col == 'C')) {
			if (tictac[2][2] != ' ')
				return true;
			else
				return false;
		}
		else 
			return false;
	}
	else
		return true;
}
bool win()
{
	if ((tictac[0][0] == tictac[0][1] && tictac[0][0] == tictac[0][2]) && (tictac[0][0] != ' '))
		return true;
	else if ((tictac[1][0] == tictac[1][1] && tictac[1][0] == tictac[1][2]) && (tictac[1][0] != ' '))
		return true;
	else if ((tictac[2][0] == tictac[2][1] && tictac[2][0] == tictac[2][2]) && (tictac[2][0] != ' '))
		return true;
	else if ((tictac[0][0] == tictac[1][0] && tictac[0][0] == tictac[2][0]) && (tictac[0][0] != ' '))
		return true;
	else if ((tictac[0][1] == tictac[1][1] && tictac[0][1] == tictac[2][1]) && (tictac[0][1] != ' '))
		return true;
	else if ((tictac[0][2] == tictac[1][2] && tictac[0][2] == tictac[2][2]) && (tictac[0][2] != ' '))
		return true;
	else if ((tictac[0][0] == tictac[1][1] && tictac[0][0] == tictac[2][2]) && (tictac[0][0] != ' '))
		return true;
	else if ((tictac[0][2] == tictac[1][1] && tictac[0][2] == tictac[2][0]) && (tictac[0][2] != ' '))
		return true;
	else
		return false;
}
void main()
{
	int row;
	char col;
	char player;
	int repeat = 0;
	int moveCount = 0;

		do {
			if (repeat == 0)
			{
				drawBoard();
				do {
					cout << "Player X: Please select your spot!" << endl;
					cout << "Row: ";
					cin >> row;
					cout << "Column: ";
					cin >> col;
					if (checkMove(row, col))
						cout << endl << "Invalid Move! Please try again." << endl << endl;
				} while (checkMove(row, col));
				makeMove(row, col, 'X');
				moveCount++;
				repeat = 1;
			}
			else if (repeat == 1 && !win())
			{
				drawBoard();
				do {
				cout << "Player O: Please select your spot!" << endl;
				cout << "Row: ";
				cin >> row;
				cout << "Column: ";
				cin >> col;
				if (checkMove(row, col))
						cout << endl << "Invalid Move! Please try again." << endl << endl;
				} while (checkMove(row, col));
				makeMove(row, col, 'O');
				moveCount++;
				repeat = 0;
			}
		} while ((!win()) && (moveCount < 9));

		if (moveCount == 9 && !win())
			cout << endl << "Tie!" << endl;
		else if (repeat == 1)
			cout << endl << "Player X Wins!!" << endl;
		else if (repeat == 0)
			cout << endl << "Player O Wins!!" << endl;
}