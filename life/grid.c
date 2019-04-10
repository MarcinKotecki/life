#include <stdlib.h>
#include <stdio.h>

#include "grid.h"

struct Grid newGrid( int width, int height ) {
    struct Grid g;
    g.width = width;
    g.height = height;
    g.cells = malloc( width * sizeof g.cells ); 
    for( int i = 0; i < width; i++ ) 
        g.cells[i] = malloc( height * sizeof g.cells );
    return g;
}

void displayGrid( struct Grid g ) {
    for( int y = 0; y < g.height; y++ ) {
        for( int x = 0; x < g.width; x++ )
            printf( "%d", g.cells[x][y] );
        printf( "\n" );
    }
    printf( "------\n" );
}

