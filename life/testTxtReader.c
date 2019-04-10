#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "txtReader.h"

int main() {
    
    struct Grid g = readGridFromTxt( "testTxtReader.txt" );
    
    int failed = 1;
    if( g.width == 3 && g.height == 2 && g.cells[0][0] == 1 && g.cells[1][0] == 0 && g.cells[2][0] == 1 && g.cells[0][1] == 0 && g.cells[1][1] == 1 && g.cells[2][1] == 0 )
        failed = 0;
    
    if( failed ) {
        printf( "testTxtReader failed\n" );
        return 1;
    } else {
        printf( "testTxtReader success\n" );
        return 0;
    }
}
