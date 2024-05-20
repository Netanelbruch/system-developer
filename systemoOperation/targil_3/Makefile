

main:libpoisson.so
	gcc -o main 3.c -ldl
	./main

libpoisson.so: poisson.c
	gcc -shared -fPIC -o libpoisson.so poisson.c -lm


.PHONY: clean

clean:
	rm main libpoisson.so

