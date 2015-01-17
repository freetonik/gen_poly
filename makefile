CC=g++
CFLAGS=-Wall -g


mainmake: main.c population.c evolution.c allinc.h
	g++ population.c evolution.c main.c 




clean:
	rm -f main main.o population.o evolution.o pq.o a.out

