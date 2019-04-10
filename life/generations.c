#include "grid.h"
#include "generations.h"

int neighboursCount( struct Grid g, int x, int y, int nState ) {
    int neighbours = 0;
    int topEdge = ( y == 0 ) ? 1 : 0;
    int leftEdge = ( x == 0 ) ? 1 : 0;
    int bottomEdge = ( y + 1 == g.height ) ? 1 : 0;
    int rightEdge = ( x + 1 == g.width ) ? 1 : 0;
    if( !topEdge && !leftEdge && g.cells[x-1][y-1] == nState ) neighbours++;
    if( !topEdge && g.cells[x][y-1] == nState ) neighbours++;
    if( !topEdge && !rightEdge && g.cells[x+1][y-1] == nState ) neighbours++;
    if( !rightEdge && g.cells[x+1][y] == nState ) neighbours++;
    if( !rightEdge && !bottomEdge && g.cells[x+1][y+1] == nState ) neighbours++;
    if( !bottomEdge && g.cells[x][y+1] == nState ) neighbours++;
    if( !bottomEdge && !leftEdge && g.cells[x-1][y+1] == nState ) neighbours++;
    if( !leftEdge && g.cells[x-1][y] == nState ) neighbours++;
    return neighbours;
}

int modifyCell( struct Grid g, int x, int y ) {
    if( ( g.cells[x][y] == OFF ) && ( neighboursCount( g, x, y, ON ) == 3 ) )
        return ON;
    if( ( g.cells[x][y] == ON ) && ( neighboursCount( g, x, y, ON ) < 2 || neighboursCount( g, x, y, ON ) > 3 ) )
        return OFF;
    return g.cells[x][y];
}

struct Grid nextGen( struct Grid g ) {
    struct Grid ng = newGrid( g.width, g.height );
    for( int y = 0; y < g.height; y++ )
        for( int x = 0; x < g.width; x++ )
            ng.cells[x][y] = modifyCell( g, x, y );
    return ng;
}
