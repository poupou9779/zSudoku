#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int get_grid_from(int[9][9], const char *);
void display_grid(int[9][9]);
int is_on_line(int, int[9][9], int);
int is_on_column(int, int[9][9], int);
int is_on_block(int, int[9][9], int, int);
void solve_grid(int[9][9]);
int is_grid_ok(int[9][9], int, int);
int estValide(int[9][9], int);

#endif
