all: compile run

compile:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Huffman.o -c ./src/Huffman.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Huffman.o ./lib/Node.o ./src/test.cpp
	
run:	
	./bin/test