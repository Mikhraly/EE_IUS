TARGET = report
CC = gcc

PREF_SRC = ./src/
PREF_INC = ./inc/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	$(CC) -c $< -o $@ -I $(PREF_INC)

clean :
	rm -rf $(TARGET) *.out *.exe $(PREF_OBJ)*.o