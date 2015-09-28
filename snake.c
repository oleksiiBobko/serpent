#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<syslog.h>
#include"snake.h"
#include"common.h"

int main(int argc, char* const argv[]) {
    
    int maxx, maxy, y=0, x=0, key;
    openlog(SNAKE, LOG_PID|LOG_CONS, LOG_USER);

    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); 
    curs_set(0);

    getmaxyx(stdscr, maxy, maxx);

    segment *h;

    if((h = malloc(sizeof(segment))) == NULL) {
        exit(-1);
    }

    h = init_snake(h, LENGTH);
    field *f = init_field(maxy, maxx);
    set_apple(f);
   
    for (x = 0; x < maxx; x++) {
        for (y = 0; y < maxy; y++) {
            if(x == 0 || x == (maxx - 1) || y == 0 || y == (maxy - 1)) {
                mvaddch(y, x, 'o');
            }
        }
    }

    while(1) {

        rewrite_snake(h);
        rewrite_field(f);
        eat(f, h);
        if(check_obstacle(f, h)) {
            h->ys = 10;
            h->xs = 10;
        }
        usleep(TIME);
        key = nb_getch();
        if(key != -1) {
        switch(key) {
            case KEY_UP:
                set_direction(h, UP);
            break;

            case KEY_DOWN:
                set_direction(h, DOWN);
            break;

            case KEY_LEFT:
                set_direction(h, LEFT);
            break;

            case KEY_RIGHT:
                set_direction(h, RIGHT);
            break;
 
            case ESCAPE:
                endwin();
                exit(0);
        }
        }
   }

   endwin();
   return 0;
}

void set_direction(segment *h, int d) {
    h->d = d;
}

void rewrite_snake(segment *h) {

    store_coords(h);
    recalc_snake(h);

    mvaddch(h->ys, h->xs, HEAD); 
    mvaddch(h->y_old, h->x_old, SEG);

    segment *s = h->next;

    store_coords(s);
    make_mv(s, h);

    segment *n;

    while(s->next != NULL) {
        n = s->next;
        store_coords(n);
        make_mv(n, s);
        s = n;
    }

    mvaddch(s->y_old, s->x_old, EMPTY);
    refresh();

} 

segment *init_snake(segment *h, int length) {

    segment *s;
    segment *n;
    int i;

    if((s = (segment *)malloc(sizeof(segment))) == NULL) {
        exit(-1);
    }

    set_init_state(s);

    h->next = s;

    for(i = 0; i <= length; i++) {
        if((n = (segment *)malloc(sizeof(segment))) == NULL) {
            exit(-1);
        }

        set_init_state(n);
        s->next = n;
        s = n;

    }

    set_init_state(h);
    h->d = RIGHT;
    return h;
}

void recalc_snake(segment *h) {
    switch(h->d) {
        case UP:
           h->ys = h->ys - 1;
        break;
        case DOWN:
          h->ys = h->ys + 1;
        break;
        case LEFT:
          h->xs = h->xs - 1;
        break;
        case RIGHT:
          h->xs = h->xs + 1;
        break;
 
    }
    
}

void rewrite_field(field *f) {
    mvaddch(f->y_apple, f->x_apple, APPLE);
    refresh();
}

int nb_getch() {
    fd_set rfds;
    struct timeval tv;
    int r = -1; 
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    select(0 + 1, &rfds, NULL, NULL, &tv);

    if (FD_ISSET(0, &rfds)) {
        r = getch();
    }

    return r;
}

