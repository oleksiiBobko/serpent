#define ESCAPE 27
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define TIME 10000
#define LENGTH 3 
#define HEAD '@'
#define EMPTY ' '
#define SEG '*'
#define APPLE '+'

typedef struct segment {
    struct segment *next;
    int xs;
    int ys;
    int x_old;
    int y_old;
    int d;
} segment;

typedef struct field {
    int height;
    int width;
    int y_apple;
    int x_apple;
} field;

segment *init_snake(int length);

void set_direction(segment *h, int d);

void rewrite_snake(segment *h);

void recalc_snake(segment *h);

void set_direction(segment *h, int d);

int nb_getch();

field *init_field(int maxy, int maxx);

void set_apple(field *f);
