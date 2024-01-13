#include <stdio.h>

#define BOARD_SIZE 8

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Print column labels
    printf("  1 2 3 4 5 6 7 8\n");
    printf(" +----------------\n");

    // Print the board with row labels
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c|", 'a' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------\n");
    }
}

void placePiece(char board[BOARD_SIZE][BOARD_SIZE], char piece, char row, int col) {
    // Place the piece on the specified position
    if (row >= 'a' && row <= 'h' && col >= 1 && col <= 8) {
        board[row - 'a'][col - 1] = piece;
    } else {
        printf("Invalid position!\n");
    }
}

int main() {
    char chessBoard[BOARD_SIZE][BOARD_SIZE];

    initializeBoard(chessBoard);

    // Place some pieces on the board
    placePiece(chessBoard, 'Q', 'd', 1); // Queen at d1
    placePiece(chessBoard, 'B', 'e', 2); // Bishop at e2
    placePiece(chessBoard, 'N', 'f', 3); // Knight at f3
    placePiece(chessBoard, 'R', 'g', 4); // Rook at g4

    // Print the board with pieces
    printBoard(chessBoard);

    return 0;
}
