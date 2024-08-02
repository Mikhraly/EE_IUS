#ifndef SNAKE_H
#define SNAKE_H


#include <stdlib.h>
#include <ncurses/ncurses.h>

enum directions{LEFT, RIGHT, UP, DOWN};

typedef struct toil {
    int x;
    int y;
    struct toil *next;
} Toil;

typedef struct head {
    int x;
    int y;
} Head;

typedef struct snake {
    int direction;
    Head head;
    Toil *toil;
} Snake;


Snake * snake_create(int y, int x, int direction);
int snake_delete(Snake *snake);
void snake_print(Snake *snake);
void snake_move(Snake **snake, int grow_up);
int snake_grow_up(Snake **snake);


#endif