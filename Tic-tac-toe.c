#include <stdio.h>

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns for a win
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// Function to check if the game is a draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    char board[3][3];  // The Tic Tac Toe board
    int row, col;     // Variables to store user input for row and column
    char currentPlayer = 'X';  // Variable to keep track of the current player

    // Initialize the board with empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Tic Tac Toe\n");
    printf("Player-1: X\n");
    printf("Player-2: O\n");
    printf("Enter row and column numbers (0-2) to make a move.\n");

    // Game loop
    while (1) {
        // Display the board
        displayBoard(board);

        // Get user input for row and column
        printf("Player %c's turn. Enter row and column: ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Validate user input
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Check if the selected position is already occupied
        if (board[row][col] != ' ') {
            printf("Position already occupied. Try again.\n");
            continue;
        }

        // Update the board with the current player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
