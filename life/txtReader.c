#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "txtReader.h"

struct Grid readGridFromTxt( char* fileName ) {
    FILE *input = fopen( fileName, "r" );
    int width, height, temp;
    fscanf(input, "%d", &width);
    fscanf(input, "%d", &height);
    struct Grid g = newGrid( width, height );
    for( int y = 0; y < height; y++ )
        for( int x = 0; x < width; x++ ) {
            fscanf(input, "%d", &temp);
            g.cells[x][y] = temp;
        }
    return g;
}