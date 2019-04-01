#ifndef _GRID_
#define _GRID_

enum cell {OFF, ON};

struct Grid {
    int width;
    int height;
    int** cells;
};

void startSimulation( char*, char*, int );
struct Grid newGrid( int, int );
void displayGrid( struct Grid ); 

#endif