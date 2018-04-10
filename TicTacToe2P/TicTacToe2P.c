//Tic Tac Toe 2 player game
//By: Peter Maksymowsky
//Date: April 9, 2018
//Completion time: ~1.5 hours

//Description: This is a 2 player Tic-Tac-Toe game. Some features that I added above a barebones game are a nicer board layout, colours for players (X and O) and the ability
//for players to input their names so it is easier to see who's turn it is. As opposed to ending the game for an illegal move, I chose to give an error/warning message to the 
//player so they can make their move again.

#include <stdio.h>
#include <stdbool.h>

#define ANSI_COLOUR_CYAN    "\x1b[36m"
#define ANSI_COLOUR_GREEN   "\x1b[32m"
#define ANSI_COLOUR_RESET   "\x1b[0m"

void printBoard (char board [5][5]);
void getPlayerName (char s[], int maxLength);
int convertPosition(char position);
bool makeMove(char board[5][5], char pTurn, int row, int col);
bool gameOver (char board[5][5]);
bool gameWon (char board[5][5], char player);
void printPAndColour (char player);


const int MAX_LENGTH = 25;

int main(void) {
	//set up board:
	char board[5][5] = { {'U','|','U','|','U'}
						,{'-','-','-','-','-'}
						,{'U','|','U','|','U'}
						,{'-','-','-','-','-'}
						,{'U','|','U','|','U'}};
	int row, col;
	char rowLetter, colLetter, pTurn, p1Name[MAX_LENGTH], p2Name[MAX_LENGTH];
	bool moveMade;
	
	//initial Query for player names
	printf("Welcome to 2 player Tic-Tac-Toe!\n");
	
	printf("Please enter player 1's name (\"");
	printPAndColour('X');
	printf("\"): ");
	getPlayerName(p1Name, MAX_LENGTH);
	
	printf("Please enter player 2's name (\"");
	printPAndColour('O');
	printf("\"): ");
	getPlayerName(p2Name, MAX_LENGTH);
	
	printBoard(board);
	
	//where moves are made
	while(!gameOver(board)) {
		moveMade = false;
		while(! moveMade && !gameOver(board)) {
			pTurn = 'X';
			
			printf("%s's (", p1Name);
			printPAndColour('X');
			printf(") move (row/col): ");
			
			scanf(" %c%c", &rowLetter, &colLetter);
			row = convertPosition(rowLetter);
			col = convertPosition(colLetter);
			moveMade = makeMove(board, pTurn, row, col);
			printBoard(board);
		}
		moveMade = false;
		while(! moveMade && !gameOver(board)) {
			pTurn = 'O';
			
			printf("%s's (", p2Name);
			printPAndColour('O');
			printf(") move (row/col): ");
			
			scanf(" %c%c", &rowLetter, &colLetter);
			row = convertPosition(rowLetter);
			col = convertPosition(colLetter);
			moveMade = makeMove(board, pTurn, row, col);
			printBoard(board);
		}
	}
	
	//game ending conditions
	if (gameWon(board, 'X')) {
		printf("%s Wins!!!\n", p1Name);
	} else if (gameWon(board, 'O')) {
		printf("%s Wins!!!\n", p2Name);
	} else {
	printf ("DRAW!!!\n");
	}
	
	return 0;
}

void printBoard (char board [5][5]) {
	printf("  a b c\n");
	for (int i = 0; i < 5; i++) {
		if(i%2 == 0) {
			printf("%c ", (char)'a'+i/2);
		} else {
			printf("  ");
		}
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == 'U') {
				printf(" ");
			} else if (board[i][j] == 'X') {
				printPAndColour('X');
			} else if (board[i][j] == 'O') {
				printPAndColour('O');
			} else {
			printf("%c", board[i][j]);
			}
		}
		printf("\n");
	}
}

void getPlayerName (char s[], int maxLength) {
	int i = 0;
	char c;
	
	while (i < maxLength && (c = getchar()) != '\n') {
		s[i++] = c;
	}
	s[i] = '\0' ;
}

//used to convert the row/col position to an int value to make life easier
int convertPosition (char position) {
	if (position == 'a') return 0;
	else if (position == 'b') return 2;
	else if (position == 'c') return 4;
	else return 0;
}

bool makeMove(char board[5][5], char pTurn, int row, int col) {
	if (board [row][col] == 'U') {
		board [row][col] = pTurn;
		return true;
	}
	else{
		printf("Invalid move, try again\n");
		return false;
	}
}

//goes through all conditions to see if the letter/player has won the game
bool gameWon (char board[5][5], char player) {
	for(int i = 0; i <= 4; i+= 2) {
		if(board[i][0] == player && board [i][2] == player && board[i][4] == player) return true;
		else if(board[0][i] == player && board [2][i] == player && board[4][i] == player) return true;
	}
	if(board[0][0] == player && board [2][2] == player && board[4][4] == player) return true;
	if(board[4][0] == player && board [2][2] == player && board[0][4] == player) return true;
	
	return false;
}

bool gameOver (char board[5][5]) {
	bool moveAvailable = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == 'U') {
				moveAvailable = true;
			}
		}
	}
	if (gameWon(board, 'X') || gameWon(board, 'O') || !moveAvailable) {
	return true;
	} else {
	return false;
	}
}

void printPAndColour (char player) {
	if (player == 'X') {
		printf(ANSI_COLOUR_CYAN "X" ANSI_COLOUR_RESET);
	} else if (player == 'O') {
		printf(ANSI_COLOUR_GREEN "O" ANSI_COLOUR_RESET);
	}
}