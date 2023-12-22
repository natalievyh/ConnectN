#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "input_validation.h"

char** create_empty_board(int num_rows, int num_cols, char blank_char) {
    /*
    creates an empty board to play on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @blank_char: the character denoting an empty space on the board
    returns: a board filled with blank characters
    */
    char** board = (char**)calloc(num_rows, sizeof(char*));
    for (int i = 0; i < num_rows; ++i) {
        board[i] = (char*)calloc(num_cols, sizeof(char));
        for (int j = 0; j < num_cols; ++j) {
            board[i][j] = blank_char;
        }
    }
    return board;
}

void place_piece(char** board, int num_rows, int num_cols, int col, char cur_player_piece, char blank_char) {
    /*
    places the player's piece on the board at the specified column
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @col: the column the user wants to place their piece in
    @cur_player_piece: the current player's piece: X if cur_player = Player 1, O if cur_player = Player 2
    @blank_char: the character denoting an empty space on the board
    */
    int row = first_available_row(board, num_rows, col, blank_char);
    board[row][col] = cur_player_piece;
    print_board(board, num_rows, num_cols);
}

bool is_valid_move(int num_args_read, char** board, int col, int num_rows, int num_cols, char blank_char) {
    /*
    checks if the player's move is valid
    @num_args_read: the number of arguments read from user input
    @board: the num_rows x num_cols matrix the game is played on
    @col: the column the user wants to place their piece in
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @blank_char: the character denoting an empty space on the board
    @return: true if the player's move is valid, otherwise false
    */
    return isValidFormat(num_args_read, 1)
            && move_on_board(col, num_cols)
            && !column_full(board, col, num_rows, blank_char);
}

bool move_on_board(int col, int num_cols) {
    /*
    checks if the user's move is on the board
    @col: the column the user wants to place their piece in
    @num_cols: number of cols on the board
    @return: true if the move is on the board, otherwise false
    */
    return (col >= 0 && col <= num_cols);
}


bool column_full(char** board, int col, int num_rows, char blank_char) {
    /*
    checks if a column is full
    @board: the num_rows x num_cols matrix the game is played on
    @col: the column the user wants to place their piece in
    @num_rows: number of rows on the board
    @blank_char: the character denoting an empty space on the board
    @return: true if the column is full, otherwise false
    */
    if (board[num_rows - 1][col] == blank_char) {
        return false;
    }
    return true;
}

int first_available_row(char** board, int num_rows, int col, char blank_char) {
    /*
    determines the location of the first available row
    @board: the num_rows x num_cols matrix the game is played on
    @col: the column the user wants to place their piece in
    @num_rows: number of rows on the board
    @blank_char: the character denoting an empty space on the board
    return: the row number of the first available row
    */
    int row = 0;
    for (int i = 0; i < num_rows; ++i) {
        if (board[i][col] == blank_char) {
            row = i;
            return row;
        }
    }
    return row;
}

void delete_board(char** board, int num_rows){
    /*
    deletes the game board
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    */
	for(int i = 0 ; i < num_rows; ++i){
		free(board[i]);
	}
	free(board);
}

void print_board(char** board, int num_rows, int num_cols) {
    /*
    prints the game board
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    */
    for (int i = num_rows - 1; i >= 0; --i) {
        printf("%d ", i);
        for (int j = 0; j < num_cols; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int k = 0; k < num_cols; ++k) {
        printf("%d ", k);
    }
    printf("\n");
}
