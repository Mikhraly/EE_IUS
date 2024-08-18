all: prog

prog: temp_api.o
	gcc temp_api.o -o prog

temp_api.o: temp_api.c temp_api.h
	gcc temp_api.c -c temp_api.o

clean:
	rm -rf *.o prog