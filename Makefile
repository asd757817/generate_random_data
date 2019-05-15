all: run

run: test
	gcc -o test data.c gen_data.c -lgsl -lgslcblas -lm &&./test


clea:
	rm -f *.o


