#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "generations.h"

int main() {
    struct Grid g = newGrid( 3, 3 );
    //1 0 1
    //0 1 0
    //0 1 0
    g.cells[0][0] = 1;
    g.cells[1][0] = 0;
    g.cells[2][0] = 1;
    g.cells[0][1] = 0;
    g.cells[1][1] = 1;
    g.cells[2][1] = 0;
    g.cells[0][2] = 0;
    g.cells[1][2] = 1;
    g.cells[2][2] = 0;
    
    int failed = 0;
    printf( "%d\n", neighboursCount( g, 0, 0, 1 ) );
    if( neighboursCount( g, 0, 0, 1 ) != 1 || neighboursCount( g, 0, 1, 0 ) != 2 || neighboursCount( g, 1, 1, 1 ) != 3 )
        failed = 1;
    
    if( failed ) {
        printf( "testGenerations failed\n" );
        return 1;
    } else {
        printf( "testGenerations success\n" );
        return 0;
    }
}
