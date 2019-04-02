#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <string.h>

#include "grid.h"
#include "pngWriter.h"

png_byte color_type;
png_byte bit_depth;
png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void saveGridAsImage( struct Grid g, char* fileName ) {
    int width = g.width;
    int height = g.height;
    bit_depth = 8;
    color_type = PNG_COLOR_TYPE_GRAY;
    number_of_passes = 7;
    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
    for( int y = 0; y < height; y++ )
        row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);
    for( int y = 0; y < height; y++ ) {
        png_byte* row = row_pointers[y];
        for( int x = 0; x < width; x++ ) 
            row[x] = g.cells[x][y] ? 255 : 0;
    }
    writeToFile( fileName, width, height );
}

char* getFileName( int i ) {
    char *fileName = malloc( 16 );
    strcpy( fileName, "output00000.png" );
    int j = 10;
    while( ( i > 0 ) && ( j > 0 ) ) {
        fileName[j--] = ( i % 10 ) + '0';
        i = i / 10;
    }
    return fileName;
}

void writeToFile(char* fileName, int width, int height) {
  FILE *fp = fopen(fileName, "wb");
  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  info_ptr = png_create_info_struct(png_ptr);
  png_init_io(png_ptr, fp);
  png_set_IHDR(png_ptr, info_ptr, width, height,
   bit_depth, color_type, PNG_INTERLACE_NONE,
   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  png_write_info(png_ptr, info_ptr);
  png_write_image(png_ptr, row_pointers);
  png_write_end(png_ptr, NULL);
  for (int y=0; y<height; y++)
    free(row_pointers[y]);
  free(row_pointers);
  fclose(fp);
}
