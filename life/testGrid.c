#include <stdlib.h>
#include <stdio.h>

#include "grid.h"

int main() {
    struct Grid g = newGrid( 3, 1 );
    
    int failed = 1;
    if( g.width == 3 && g.height == 1 && g.cells[0][0] == 0  && g.cells[1][0] == 0 && g.cells[2][0] == 0 )
        failed = 0;
    
    if( failed ) {
        printf( "testGrid failed\n" );
        return 1;
    } else {
        printf( "testGrid success\n" );
        return 0;
    }
}
