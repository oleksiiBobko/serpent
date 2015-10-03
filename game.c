#include<stdlib.h>
#include<syslog.h>
#include"snake.h"

field *init_field(int height, int width) {
    field *f;

    if((f = (field *)malloc(sizeof(field))) == NULL) {
        exit(-1);
    }
    f->width = width;
    f->height = height;
    return f;
}

void set_apple(field *f) {
    time_t t;
    srand((unsigned)time(&t));
    f->x_apple = (rand() % (f->width - 2)) + 1;
    f->y_apple = (rand() % (f->height - 2)) + 1;

}

void eat(field *f, segment *h) {

    write_log("begin editing");
    syslog(LOG_INFO, "begin eating");

    segment *n;
    segment *s = h->next;

    if(f->y_apple == h->ys && f->x_apple == h->xs) {
        
        if((n = malloc(sizeof(segment))) == NULL) {
            exit(-1);
        }

        n->y_old = -1;
        n->x_old = -1;
        n->next = NULL;

        while(s->next != NULL) {
            s = s->next;
        }

        s->next = n;

        set_apple(f); 
 
    }

    syslog(LOG_INFO, "end eating");

}

int check_obstacle(field *f, segment *h) {
    if(h->ys <= 1 && h->d == UP) {
        return TRUE;
    } else if(h->xs <= 1 && h->d == LEFT) {
        return TRUE;	    
    } else if(h->ys >= (f->height - 2) && h->d == DOWN) {
        return TRUE;	    
    } else if(h->xs >= (f->width - 2) && h->d == RIGHT) {
        return TRUE;
    } 
    
    return FALSE;
}
