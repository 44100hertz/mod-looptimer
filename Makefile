CFLAGS=-Wall -g

default: bin/notecalc

bin/notecalc: src/notecalc.c
	gcc -o notecalc src/notecalc.c -lm

.PHONY: default clean
