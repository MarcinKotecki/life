#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grid.h"

int main( int argc, char** argv ) {
    char input[256] = "input";
    char output[256] = "output";
    int inputProvided = 0;
    int saveToFile = 0;
    int generations = 5;
    for( int i = 1; i < argc - 1; i++ ) {
        if( strcmp( argv[i], "-in" ) == 0 ) {
            strcpy( input, argv[i + 1] );
            inputProvided = 1;
            i++;
        } else if( strcmp( argv[i], "-out" ) == 0 ) {
            strcpy( output, argv[i + 1]);
            saveToFile = 1;
            i++;
        } else if( strcmp( argv[i], "-gen" ) == 0 ) {
            generations = atoi( argv[i+1] );
            i++;
        }
    }
    if( !inputProvided ) {
        printf( "No input file.\n" );
        return 1;
    }

    startSimulation( input, output, generations );

    return 0;
}
