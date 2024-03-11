CC = gcc

notinc: notinc_test.c
	${CC} notinc_test.c notinc.c -o notinc_test && ./notinc_test

