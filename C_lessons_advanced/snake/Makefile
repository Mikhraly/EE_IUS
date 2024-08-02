TARGET = go_snake
CC = gcc

PREF_SRC = ./src/
PREF_INC = ./inc/
PREF_OBJ = ./obj/
PREF_OUT = ./out/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)
	mkdir -p $(PREF_OUT)
	$(CC) $(OBJ) -o $(PREF_OUT)$(TARGET) -lncurses -I C:/msys64/ucrt64/include/ncurses -DNCURSES_STATIC

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	mkdir -p $(PREF_OBJ)
	$(CC) -c $< -o $@ -I $(PREF_INC) -lncurses -I C:/msys64/ucrt64/include/ncurses -DNCURSES_STATIC

clean :
	rm -rf $(PREF_OUT)* $(PREF_OBJ)*.o