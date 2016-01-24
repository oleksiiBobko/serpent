#include<stdlib.h>
#include<syslog.h>
#include<time.h>
#include"serpent.h"

field *init_field(int height, int width) {
    field *f;

    if((f = (field *)malloc(sizeof(field))) == NULL) {
        exit(-1);
    }
    f->width = width;
    f->height = height;
    f->next = NULL;
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

    segment *n;
    segment *s = h->next;

    if(f->y_apple == h->ys && f->x_apple == h->xs) {
        
        h->counter++; 

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

        if((h->counter - LENGTH) % LVL == 0) {
            lvl_up(f, h->counter);
        }

        set_apple(f); 
 
    }

    syslog(LOG_INFO, "end eating");

}

void lvl_up(field *f, int count) {
    int lvl = count / LVL;

    obs *o;
    //int h = field->height;
    //int w = field->width;
    
    switch(lvl) {
        case 1:
            if((o = (obs *)malloc(sizeof(obs))) == NULL) {
                exit(-1);
            }
            o->x = 10;
            o->y = 15;
            f->next = o;
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;    
    }
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

    int x_head = h->xs;
    int y_head = h->ys;
    unsigned char direction = h->d;

    while(h->next != NULL) {
        h = h->next;
        switch(direction) {
            case UP:
                if(h->ys == y_head - 1 && h->xs == x_head) {
                    return TRUE;
                }
            break;
            case DOWN:
                if(h->ys == y_head + 1 && h->xs == x_head) {
                    return TRUE;
                }
            break;
            case LEFT:
                if(h->ys == y_head && h->xs == x_head - 1) {
                    return TRUE;
                }
            break;
            case RIGHT:
                if(h->ys == y_head && h->xs == x_head + 1) {
                    return TRUE;
                }
            break;
        }
   }
    
    return FALSE;
}
