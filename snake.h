#define ESCAPE 27
#define UP 0
#define DOWN 255 
#define LEFT 2
#define RIGHT 253
#define TIME 90000
#define LENGTH 3 
#define HEAD '@'
#define EMPTY ' '
#define SEG '*'
#define APPLE '+'
#define BORDER 'o'
#define SNAKE "snake"
#define LIFE 5
#define LVL 5

#define DEBUG_MODE 1 
#define TRUE 1
#define FALSE 0

#define PI 3.14159265

typedef struct segment {
    struct segment *next;
    int xs;
    int ys;
    int x_old;
    int y_old;
    int counter;
    int life;
    unsigned char d;
} segment;

typedef struct field {
    int height;
    int width;
    int y_apple;
    int x_apple;
    struct obs *next;
} field;

<<<<<<< HEAD
typedef struct obs {
    int x;
    int y;
    struct obs *next;
    struct obs *prev;
} obs;
=======
typedef struct point {
    int x;
    int y;
} point;
>>>>>>> ec823e91a435d93b39848f4e29f98d90ab8928cd

segment *init_snake(segment *h, int length, int maxy);

void set_direction(segment *h, unsigned char d);

void rewrite_snake(segment *h);

void rewrite_field(field *f);

void recalc_snake(segment *h);

int nb_getch();

field *init_field(int maxy, int maxx);

void set_apple(field *f);

void eat(field *f, segment *h);

//void lvl_up(field *f, int count);

int check_obstacle(field *f, segment *h);

void vanish_snake(segment *head);

void point_on_circle(float r, float a, int oy, int ox, point *p);
