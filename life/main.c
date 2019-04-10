#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grid.h"
#include "generations.h"
#include "txtReader.h"
#include "txtWriter.h"
#include "pngWriter.h"

int main( int argc, char** argv ) {
    char input[256] = "input";
    char output[256] = "output";
    int inputProvided = 0;
    int saveToFile = 0;
    int generations = 5;
    int scale = 1;
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
        } else if( strcmp( argv[i], "-scale" ) == 0 ) {
            scale = atoi( argv[i+1] );
            i++;
        }
    }
    if( !inputProvided ) {
        printf( "No input file.\n" );
        return 1;
    }

    struct Grid g = readGridFromTxt( input );
    for( int i = 0; i < generations; i++ ) {
        g = nextGen( g );
        saveGridAsImage( g, getFileName(i), scale );
    }
    writeGridToTxt( g, output );

    return 0;
}


