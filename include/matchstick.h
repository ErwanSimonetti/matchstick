/*
** EPITECH PROJECT, 2020
** 102_architect.h
** File description:
** header
*/

int my_putstr(char const *str);
int my_getnbr(char const *str);
long long get_lglg(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int print_error_msg(char const *str);
void print_error_nbr(int const nb);

int matchstick (int sticks, int max_removed);
int check_errors (int ac, char const * const av[]);
int get_size_buffer (int lines);
int get_line_len(char *sticks);
char *write_sticks (int lines);
int get_nb_sticks (int current_line);
int get_max_sticks(int lines);
int launch_game(char *buffer, int lines, int max_removed);
void sub_player_sticks(int line, int *matches, char *sticks, int max_removed);
void sub_sticks(char *sticks, int line, int matches);
int get_matches_p (int *matches, int max_removed);
int line_empty(char *sticks, int line);
char *remove_back_n(char *str);
int game_lost(char *sticks);
int ai_turn(char *sticks, int lines, int max_removed);
void print_pre_sentence(int line, int matches, int player);