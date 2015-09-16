#include<stdlib.h>
#include"snake.h"

field *init_field(int width, int height) {
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
