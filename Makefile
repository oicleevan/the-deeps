adventure:
	g++ build/adventure.o -o bin/adventure

adventure.o:
	g++ -c src/adventure.cpp -o build/adventure.o