#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "txtWriter.h"

int main() {
    
	struct Grid g = newGrid( 3, 3 );
	writeGridToTxt( g, "testTxtWriter.txt" );
    
    FILE *f = fopen( "testTxtWriter.txt", "r" );
    int failed = 0;
    int width, height, temp;
    fscanf(f, "%d", &width);
    fscanf(f, "%d", &height);
    if( width != 3 || height != 3 )
        failed = 1;
    for( int y = 0; y < height; y++ )
        for( int x = 0; x < width; x++ ) {
            fscanf(f, "%d", &temp);
            if( temp != 0 )
                failed = 1;
        }
    fclose(f);
    
    if( failed ) {
        printf( "testTxtWriter failed\n" );
        return 1;
    } else {
        printf( "testTxtWriter success\n" );
        return 0;
    }
}
