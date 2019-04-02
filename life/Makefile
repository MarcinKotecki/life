gif: 
	ffmpeg -i output%05d.png output.gif 

main: main.c grid.c generations.c pngWriter.c txtWriter.c txtReader.c
	cc main.c grid.c generations.c pngWriter.c txtWriter.c txtReader.c -lpng -o life.out
