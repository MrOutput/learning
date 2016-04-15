#ifndef WORKSPACE
#include <ncurses.h>

#define WORKSPACE

#define MAX_X COLS
#define MAX_Y LINES

#define QTR_X (MAX_X / 4)
#define QTR_Y (MAX_Y / 4)

#define CNTR_X (MAX_X / 2)
#define CNTR_Y (MAX_Y / 2)

#define ORIGIN_X 0
#define ORIGIN_Y 0

static char collections_flag;

WINDOW *collections;
WINDOW *shell;
WINDOW *documents;

WINDOW *create_newwin(int height, int width, int starty, int startx);

void reset_workspace(void);
void destroy_win(WINDOW *local_win);
#endif
