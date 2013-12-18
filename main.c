#include "functions.h"

int main(void)
{
    int grid[9][9];
    if(get_grid_from(grid, "grid.txt") == 0)
        return -1;
    display_grid(grid);
    solve_grid(grid);
    display_grid(grid);
    return 0;
}
