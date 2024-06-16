TARGET = report
CC = gcc

all : $(TARGET)

$(TARGET) : report.o temp_api.o
	$(CC) report.o temp_api.o -o $(TARGET)

report.o : report.c
	$(CC) -c report.c -o report.o

temp_api.o : temp_api.c temp_api.h
	$(CC) -c temp_api.c -o temp_api.o

clean :
	rm -rf $(TARGET) *.o