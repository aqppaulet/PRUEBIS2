main.exe: build/main.o build/page.o build/bufferpoolmanager.o
	g++ build/main.o build/page.o build/bufferpoolmanager.o -o main.exe

build/main.o: main.cpp | build
	g++ -c main.cpp -o build/main.o

build/page.o: src/Page.cpp | build
	g++ -c src/Page.cpp -o build/page.o

build/bufferpoolmanager.o: src/BufferPoolManager.cpp | build
	g++ -c src/BufferPoolManager.cpp -o build/bufferpoolmanager.o

build:
	mkdir -p build

run: main.exe
	./main.exe