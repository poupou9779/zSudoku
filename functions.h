#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LENGTH_BUFFER 128

void get_grid_from_buffer_line(int[9][9], const char *);
void display_grid(int[9][9]);
int is_on_line(int, int[9][9], int);
int is_on_column(int, int[9][9], int);
int is_on_block(int, int[9][9], int, int);
#define solve_grid(g) solve_grid_x_y(g, 0, 0)
int solve_grid_x_y(int grid[9][9], int x, int y);

#endif
