#ifndef BOARD_H
    #define BOARD_H
    #include <stdbool.h>
    char** create_empty_board(int num_rows, int num_cols, char blank_char);
    void place_piece(char** board, int num_rows, int num_cols, int col, char cur_player_piece, char blank_char);
    bool is_valid_move(int num_args_read, char** board, int col, int num_rows, int num_cols, char blank_char);
    bool move_on_board(int col, int num_cols);
    bool column_full(char** board, int col, int num_rows, char blank_char);
    int first_available_row(char** board, int num_rows, int col, char blank_char);
    void delete_board(char** board, int num_rows);
    void print_board(char** board, int num_rows, int num_cols);
#endif