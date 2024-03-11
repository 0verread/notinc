CC = gcc

notinc: notinc_test.c
	${CC} notinc_test.c src/notinc.c -o notinc_test && ./notinc_test

