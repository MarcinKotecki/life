#ifndef _IMG_
#define _IMG_

void writeToFile(char* fileName, int width, int height);
void saveGridAsImage( struct Grid g, char* fileName );
char* getFileName( int i );

#endif
