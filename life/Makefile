gif: 
	ffmpeg -i output%05d.png output.gif 

main: main.c grid.c generations.c pngWriter.c txtWriter.c txtReader.c
	cc main.c grid.c generations.c pngWriter.c txtWriter.c txtReader.c -lpng -o life.out

testTxtWriter: grid.c txtWriter.c testTxtWriter.c
	cc grid.c txtWriter.c testTxtWriter.c -o testTxtWriter.out
	./testTxtWriter.out

testTxtReader: grid.c txtReader.c testTxtReader.c
	cc grid.c txtReader.c testTxtReader.c -o testTxtReader.out
	./testTxtReader.out
	
testGrid: grid.c testGrid.c
	cc grid.c testGrid.c -o testGrid.out
	./testGrid.out
	
testGenerations: grid.c generations.c testGenerations.c
	cc grid.c generations.c testGenerations.c -o testGenerations.out
	./testGenerations.out
	
testAll: main.c grid.c generations.c pngWriter.c txtWriter.c txtReader.c
	make testTxtReader
	make testTxtWriter
	make testGrid
