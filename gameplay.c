#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "gameplay.h"
#include "board.h"
#include "win.h"

void setup_game(int argc, char** argv, char** *out_board, int *num_rows, int *num_cols, int *num_pieces_to_win, char blank_char) {
    /* 
    sets up the game and board
    @argc: the number of arguments inputted on the command line
    @argv: the array of command line arguments
    @out_board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @num_pieces_to_win: the number of pieces needed in a row to win
    @blank_char: the character denoting an empty space on the board
    */
    get_valid_input(argc, argv, num_rows, num_cols, num_pieces_to_win);
    char** board = create_empty_board(*num_rows, *num_cols, blank_char);
    *out_board = board;
    print_board(board, *num_rows, *num_cols);
}

void play_game(char** board, int num_rows, int num_cols, int num_pieces_to_win, int blank_char, int cur_player, char *cur_player_piece) {
    /*
    steps to play the game
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @num_pieces_to_win: the number of pieces needed in a row to win
    @blank_char: the character denoting an empty space on the board
    @cur_player: the current player (0 means Player 1, 1 means Player 2)
    @cur_player_piece: the current player's piece (Player 1 is 'X', Player 2 is 'O')
    */
    while (true) {
        cur_player_takes_turn(board, num_rows, num_cols, blank_char, *cur_player_piece);
        if (game_over(board, num_rows, num_cols, num_pieces_to_win, blank_char)) {
            break;
        }
        *cur_player_piece = switch_players(&cur_player, *cur_player_piece);
    }
    announce_results(board, num_rows, num_cols, num_pieces_to_win, cur_player, blank_char);
}

void cur_player_takes_turn(char**board, int num_rows, int num_cols, char blank_char, char cur_player_piece) {
    /*
    the current player takes their turn
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @blank_char: the character denoting an empty space on the board
    @cur_player_piece: the current player's piece (Player 1 is 'X', Player 2 is 'O')
    */
	int col;
	get_valid_move_from_player(board, &col, num_rows, num_cols, blank_char);
	place_piece(board, num_rows, num_cols, col, cur_player_piece, blank_char);
}

void get_valid_move_from_player(char** board, int* out_col, int num_rows, int num_cols, char blank_char) {
    /*
    Gets a valid move from the player
    @board: the num_rows x num_cols matrix the game is played on
    @out_col: the column the user wants to put their piece in
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @blank_char: the character denoting an empty space on the board
    */
    int num_args_read;
    do { 
        printf("Enter a column between 0 and %d to play in: ", num_cols - 1);
        num_args_read = scanf("%d", out_col);
    } while (!is_valid_move(num_args_read, board, *out_col, num_rows, num_cols, blank_char));
}

char switch_players(int* cur_player, char cur_player_piece) {
    /*
    switch players
    @cur_player: the current player (0 means Player 1, 1 means Player 2)
    @cur_player_piece: the current player's piece (Player 1 is 'X', Player 2 is 'O')
    @return: the current player's piece
    */
    *cur_player = ((*cur_player) + 1 ) % 2;
    if (*cur_player == 0) {
        cur_player_piece = 'X';
    } else {
        cur_player_piece = 'O';
    }
    return cur_player_piece;
}

void announce_results(char** board, int num_rows, int num_cols, int num_pieces_to_win, int cur_player, char blank_char) {
    /*
    announce the results of the game (someone won or tie)
    @board: the num_rows x num_cols matrix the game is played on
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @num_pieces_to_win: the number of pieces needed in a row to win
    @blank_char: the character denoting an empty space on the board
    @cur_player: the current player (0 means Player 1, 1 means Player 2)
    */
    if (someone_won(board, num_rows, num_cols, num_pieces_to_win, blank_char)) {
        if (cur_player == 0) {
            printf("Player 1 Won!\n");
        } else {
            printf("Player 2 Won!\n");
        }
    } else {
        printf("Tie game!\n");
    }
}



void get_valid_input(int argc, char** argv, int* num_rows, int* num_cols, int* num_pieces_to_win) {
    /*
    get valid input from the user (number of rows, columns, and pieces to win)
    @argc: the number of arguments inputted on the command line
    @argv: the array of command line arguments
    @num_rows: number of rows on the board
    @num_cols: number of cols on the board
    @num_pieces_to_win: the number of pieces needed in a row to win
    */
    int num_args_read, num;
    char should_be_empty;

    if (argc < 4) {
        printf("Not enough arguments entered \nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    } 
    else if (argc > 4) {
        printf("Too many arguments entered \nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }

    for (int i = 1; i < argc; ++i) {
        num_args_read = sscanf(argv[i], "%d %c", &num, &should_be_empty);
        if (num_args_read == 1) {
            *argv[i] = num;
        } else {
            printf("Invalid format Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
        if (*argv[i] <= 0) {
            printf("Must be greater than 0 Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
    }

    *num_rows = *argv[1];
    *num_cols = *argv[2];
    *num_pieces_to_win = *argv[3];
}