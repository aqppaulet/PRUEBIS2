main: build/main.o build/page.o build/bufferpoolmanager.o build/buffer.o build/lru.o
	g++ build/main.o build/page.o build/bufferpoolmanager.o build/buffer.o build/lru.o -o main

build/main.o: main.cpp | build
	g++ -c main.cpp -o build/main.o

build/page.o: src/Page.cpp | build
	g++ -c src/Page.cpp -o build/page.o

build/buffer.o: src/Page.cpp | build
	g++ -c src/Buffer.cpp -o build/buffer.o

build/bufferpoolmanager.o: src/BufferPoolManager.cpp | build
	g++ -c src/BufferPoolManager.cpp -o build/bufferpoolmanager.o

build/lru.o: src/LRU.cpp | build
	g++ -c src/LRU.cpp -o build/lru.o

build:
	mkdir -p build

run: main clean
	./main

clean:
		rm -rf build