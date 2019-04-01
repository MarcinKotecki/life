#ifndef _GENERATIONS_
#define _GENERATIONS_

#include "grid.h"

int neighboursCount( struct Grid, int, int, int nState );
int modifyCell( struct Grid, int, int );
struct Grid nextGen( struct Grid );

#endif