#include <ncurses/ncurses.h> // подключаем библиотеку ncurses
#include <time.h>
#include "snake.h"


int main(int argc,char *argv[])
{
    initscr();      // инициализация (должна быть выполнена перед использованием ncurses)
    noecho();       // выкл отображение вводимых символов
    curs_set(0);    // выкл моргание курсора
    keypad(stdscr, 1);  // вкл нажатие стрелок
    // raw();          // Отключаем buffering   
    // Измеряем размер экрана в рядах и колонках
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    int y = y_max / 2;
    int x = x_max / 2;
    
    Snake *snake = snake_create(y, x, RIGHT);
    snake_move(&snake, 1);
    snake_move(&snake, 1);
    snake_move(&snake, 1);
    snake_move(&snake, 1);
    snake_move(&snake, 1);
    snake_move(&snake, 1);

    snake_print(snake);

    timeout(30);
    for (int key = getch();
        key != 27 && key != 'q' && key != 'Q';    // 27 - ESC
        key = getch()
    ) {
        
        // clear();
        if (key == KEY_UP)
            snake->direction = UP;
        else if (key == KEY_DOWN)
            snake->direction = DOWN;
        else if (key == KEY_LEFT)
            snake->direction = LEFT;
        else if (key == KEY_RIGHT)
            snake->direction = RIGHT;

        snake_move(&snake, 0);
        snake_print(snake);
    }


    snake_delete(snake);
    // getch();
    // refresh();  // обновить экран    
    endwin(); // завершение работы с ncurses
    return 0;
}