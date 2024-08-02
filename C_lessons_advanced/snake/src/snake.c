#include "snake.h"


Snake * snake_create(int y, int x, int direction) {
    Snake *snake = (Snake *)malloc(sizeof(Snake));
    snake->direction = direction;
    snake->head.x = x;
    snake->head.y = y;
    snake->toil = NULL;
}

int snake_delete(Snake *snake) {
    if (snake == NULL)
        return -1;

    Toil *current = snake->toil;
    Toil *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    free(snake);
    return 0;
}

void snake_print(Snake *snake) {
    mvaddch(snake->head.y, snake->head.x, '@');
    for (Toil *t = snake->toil; t; t = t->next) {
        mvaddch(t->y, t->x, '*');
    }
}

void snake_move(Snake **snake, int grow_up) {
    int x = (*snake)->head.x;
    int y = (*snake)->head.y;

    switch ((*snake)->direction) {
    case LEFT:
        (*snake)->head.x--;
        break;
    case RIGHT:
        (*snake)->head.x++;
        break;
    case UP:
        (*snake)->head.y--;
        break;
    case DOWN:
        (*snake)->head.y++;
        break;
    default:
        break;
    }

    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    if ((*snake)->head.x == x_max)
        (*snake)->head.x = 0;
    else if ((*snake)->head.x == -1)
        (*snake)->head.x = x_max - 1;
    else if ((*snake)->head.y == y_max)
        (*snake)->head.y = 0;
    else if ((*snake)->head.y == -1)
        (*snake)->head.y = y_max - 1;

    int x_next, y_next;
    Toil **t;
    for (t = &((*snake)->toil); *t; t = &((*t)->next)) {
        x_next = (*t)->x;
        y_next = (*t)->y;
        (*t)->x = x;
        (*t)->y = y;
        x = x_next;
        y = y_next;
    }

    if (grow_up != 0) {
        *t = (Toil *)malloc(sizeof(Toil));
        (*t)->x = x;
        (*t)->y = y;
        (*t)->next = NULL;
    } else {
        mvaddch(y, x, ' ');
    }
}

int snake_grow_up(Snake **snake) {
    if (*snake == NULL)
        return -1;

    
}