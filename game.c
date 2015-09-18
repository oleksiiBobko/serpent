#include<stdlib.h>
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
    f->x_apple = (rand() % (f->width - 1)) + 1;
    f->y_apple = (rand() % (f->height - 1)) + 1;

}

void eat(field *f, segment *h) {

    segment *n;
    segment *s = h->next;

    if(f->y_apple == h->ys && f->x_apple == h->xs) {
        
        if((n = malloc(sizeof(segment))) == NULL) {
            exit(-1);
        }

        n->y_old;
        n->x_old;

        while(s->next != NULL) {
            s = s->next;
        }

        s->next = n;

        set_apple(f); 
 
    }
}
