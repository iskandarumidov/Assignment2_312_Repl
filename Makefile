# all: clean a.out

a.out: main.cpp matrix.o reader.o matrix.h
	g++ main.cpp ./out/matrix.o -o ./out/a.out

matrix.o:
	g++ -c matrix.cpp -o ./out/matrix.o

reader.o:
	g++ reader.cpp matrix.cpp -o ./out/reader.out

clean: 
	rm ./out/*
