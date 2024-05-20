
SEED=100
SIZE=10000

all: main


main: 5.c
	gcc -pg 5.c -o main

run:
	./main $(SEED) $(SIZE)
	gprof main gmon.out > analysis.txt




.PHONY: all clean run

clean:
	rm main analysis.txt gmon.out