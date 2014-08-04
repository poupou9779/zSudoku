#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*#define DISPLAY*/

int main(void)
{
    int grid[9][9];
    int count = 0,
        won = 0,
        tmp;
    clock_t beg, end, total = 0;
    char buffer[LENGTH_BUFFER];
    FILE *file_grids = fopen("grid.txt", "r");
    if(file_grids == NULL)
        return -1;
    while(fgets(buffer, LENGTH_BUFFER, file_grids) != NULL)
    {
        if(buffer[0] == '#')
            continue;
        get_grid_from_buffer_line(grid, buffer);
        printf("#%d", count+1);
#ifndef DISPLAY
        putchar('\t');
#else
        putchar('\n');
        display_grid(grid);
#endif
        beg = clock();
        tmp = solve_grid(grid);
        end = clock();
        total += end-beg;
        if(tmp == 1)
        {
#ifdef DISPLAY
            display_grid(grid);
#endif
            printf("done in %u ms\n---------------------------------\n", end-beg);
            ++won;
        }
        else
            printf("isn't solved\n");
        ++count;
    }
    printf("results :\n"
           "count | won | total time | average time\n"
           "----------------------------------\n"
           " %3d  | %3d |  %5u ms  |    %.3g ms\n"
           , count, won, total, total/(double)count);
    return 0;
}

