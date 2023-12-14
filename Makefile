all: release debug

release: build/release/doodle-jump

build/release/doodle-jump: main.cpp
	mkdir -p build/release
	clang++ -O3 main.cpp -o build/release/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system

#debug: main.cpp
#	clang++ -g main.cpp -o build/debug/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system 

debug: build/debug/doodle-jump


build/debug/doodle-jump: main.cpp
	mkdir -p build/debug
	clang++ -g main.cpp -o build/debug/doodle-jump -lsfml-graphics -lsfml-window -lsfml-system 
	
compile: main.o

main.o: main.cpp
	clang++ -c main.cpp

link: doodle-jump

doodle-jump: main.o
	clang++ main.o -o doodle-jump -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o doodle-jump
	rm -rf build
