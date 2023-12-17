all: release debug

release: build/release/doodle-jump

build/release/doodle-jump: main.cpp build/release/images
	mkdir -p build/release
	clang++ -O3 main.cpp -o build/release/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system

#debug: main.cpp
#	clang++ -g main.cpp -o build/debug/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system 

debug: build/debug/doodle-jump


build/debug/doodle-jump: main.cpp build/debug/images
	mkdir -p build/debug
	clang++ -g main.cpp -o build/debug/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system 
	
build/release/images: 
	mkdir -p build/release/images
	cp ./images/* ./build/release/images/

build/debug/images: 
	cp -r ./images ./build/debug

compile: main.o

main.o: main.cpp
	clang++ -c main.cpp

link: doodle-jump

doodle-jump: main.o
	clang++ main.o -o doodle-jump -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o doodle-jump
	rm -rf build

install:
	ln -s "${PWD}/build/release/doodle-jump" /usr/local/bin
