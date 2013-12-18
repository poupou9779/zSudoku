#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

int get_grid_from(int grid[9][9], const char *path)
{
    FILE *file_grid = fopen(path, "r");
    if(file_grid != NULL)
    {
        int i,
            j;
        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j)
                grid[i][j] = fgetc(file_grid) - '0';
            fgetc(file_grid);
        }
        fclose(file_grid);
        return 1;
    }
    return 0;
}

void display_grid(int grid[9][9])
{
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
            printf(!((j+1) % 3) ? "%d|" : "%d ", grid[i][j]);
        putchar('\n');
        if (!((i+1) % 3))
            printf("------------------\n");
    }
    putchar('\n');
}

int is_on_line(int n, int grid[9][9], int line)
{
    int i;
    for(i = 0; i < 9; ++i)
        if(grid[line][i] == n)
            return 1;
    return 0;
}

int is_on_column(int n, int grid[9][9], int column)
{
    int i;
    for(i = 0; i < 9; ++i)
        if(grid[i][column] == n)
            return 1;
    return 0;
}

int is_on_block(int n, int grid[9][9], int x, int y)
{
    int i = 3*(x/3),
        j = 3*(y/3);
    for(x = i; x < i+3; ++x)
        for(y = j; y < j+3; ++y)
            if(grid[x][y] == n)
                return 1;
    return 0;
}

void solve_grid(int grid[9][9])
{
    printf("%s solved\n\n", is_grid_ok(grid, 0, 0) == 1 ? "is" : "isn't");
}

int is_grid_ok(int grid[9][9], int x, int y)
{
    int n;
    /*if the whole grid has been tested, it's ok*/
    if(y == 9)
        return 1;
    /*if this case is correct, test the next case*/
    if(grid[x][y] != 0)
        return is_grid_ok(grid, (x+1)%9, y+((x+1)/9));
    /*otherwise, test each possibility for the case grid[x][y]*/
    for(n = 1; n <= 9; ++n)
    {
        if(!is_on_line(n, grid, x) && !is_on_column(n, grid, y) && !is_on_block(n, grid, x, y))
        {
            grid[x][y] = n;
            if(is_grid_ok(grid, (x+1)%9, y+((x+1)/9)))
                return 1;
        }
        grid[x][y] = 0;
    }
    return 0;
}

