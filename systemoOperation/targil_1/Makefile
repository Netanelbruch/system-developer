
CC=gcc


all: division reco pointer

division: division.o
	$(CC) division.o -o division
reco: reco.o
	$(CC) reco.o -o reco
pointer:pointer.o
	$(CC) pointer.o -o pointer


division.o: division.c
	$(CC) -g -c division.c -o division.o
reco.o: reco.c
	$(CC) -g -c reco.c -o reco.o
pointer.o:pointer.c
	$(CC) -g -c pointer.c -o pointer.o

run:
	./reco || ./pointer  || ./division  

.PHONY: all clean

clean:
	rm division reco pointer *.o
