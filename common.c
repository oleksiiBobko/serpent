#include<syslog.h>
#include"serpent.h"
#include"common.h"

void store_coords(segment *s) {
    s->y_old = s->ys;
    s->x_old = s->xs;
}

void make_mv(segment *dst, segment *src) {
    dst->ys = src->y_old;
    dst->xs = src->x_old;
}

void set_init_state(segment *s) {
    s->ys = 10;
    s->xs = 10;
    s->y_old = -1;
    s->x_old = -1;
}

int is_debug() {
    return DEBUG_MODE;
}

void write_log(char *message) {
    if(is_debug()) {
        syslog(LOG_INFO, message);
    }
}
