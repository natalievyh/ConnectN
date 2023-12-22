#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"
#include "board.h"
#include "win.h"

/*
Play Connect-n, a version of Connect-4 where the board dimensions 
and number of pieces needed to win are user-specified
*/

int main(int argc, char** argv) {
    int cur_player = 0; // 0 means it's player 1's turn, 1 means it's player 2's turn
    char cur_player_piece = 'X'; // Player 1 starts with the X piece
    const char blank_char = '*';
    int num_rows, num_cols, num_pieces_to_win; // get from command line
    char** board;
    
    setup_game(argc, argv, &board, &num_rows, &num_cols, &num_pieces_to_win, blank_char);
    play_game(board, num_rows, num_cols, num_pieces_to_win, blank_char, cur_player, &cur_player_piece);
    delete_board(board, num_rows);
    return 0;
}
