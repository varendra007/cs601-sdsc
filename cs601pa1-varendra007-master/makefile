CFLAGS = -g -Wall -Wshadow --pedantic  -Wvla -Werror -lm

bin/vectorprod: src/vectorprod.cpp  outDir build/scprod.o
	g++ $(CFLAGS) -I./inc src/vectorprod.cpp build/scprod.o -o bin/vectorprod
outDir: 
	mkdir -p bin build
build/scprod.o: src/scprod.cpp inc/scprod.h
	g++ $(CFLAGS) -I./inc/ -c src/scprod.cpp -o build/scprod.o
