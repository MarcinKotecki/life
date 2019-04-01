#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "txtWriter.h"

void writeGridToTxt( struct Grid g, char* fileName ) {
	FILE *f = fopen( fileName, "w" );
    	
	fprintf( f, "%d ", g.width );
    	fprintf( f, "%d\n", g.height );
    
	for( int y = 0; y < g.height; y++ ) {
        
		for( int x = 0; x < g.width; x++ )
            		fprintf( f, "%d ", g.cells[x][y] );
		
		fprintf( f, "\n" );
	}
}
