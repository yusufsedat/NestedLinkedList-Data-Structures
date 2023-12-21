all: build run 

build:
	g++ -o ./lib/main.o -c ./src/main.cpp
	g++ -o ./lib/satirListesi.o -c ./src/satirListesi.cpp
	g++ -o ./lib/satirListesiDugum.o -c ./src/satirListesiDugum.cpp
	g++ -o ./lib/yoneticiListesi.o -c ./src/yoneticiListesi.cpp
	g++ -o ./lib/yoneticiListesiDugum.o -c ./src/yoneticiListesiDugum.cpp

	g++ -o ./bin/main ./lib/main.o ./lib/satirListesi.o ./lib/yoneticiListesi.o \
	./lib/yoneticiListesiDugum.o ./lib/satirListesiDugum.o

run:
	./bin/main