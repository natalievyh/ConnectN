#ifndef GAMEPLAY_H
    #define GAMEPLAY_H
    void setup_game(int argc, char** argv, char** *out_board, int *num_rows, int *num_cols, int *num_pieces_to_win, char blank_char);
    void play_game(char** board, int num_rows, int num_cols, int num_pieces_to_win, int blank_char, int cur_player, char *cur_player_piece);
    void cur_player_takes_turn(char**board, int num_rows, int num_cols, char blank_char, char cur_player_piece);
    void get_valid_move_from_player(char** board, int* out_col, int num_rows, int num_cols, char blank_char);
    char switch_players(int* cur_player, char cur_player_piece);
    void announce_results(char** board, int num_rows, int num_cols, int num_pieces_to_win, int cur_player, char blank_char);
    void get_valid_input(int argc, char** argv, int* num_rows, int* num_cols, int* num_pieces_to_win);
#endif