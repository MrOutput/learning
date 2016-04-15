#include <ncurses.h>
#include "workspace.h"

int main(int argc, char *argv[])
{	
    // Init
	initscr();
	cbreak();
    noecho();

	keypad(stdscr, TRUE);

	refresh();

    // Create windows
    reset_workspace();
    mvwprintw(documents, 20, 10, "hello");
    wrefresh(documents);

    // Key listener & handler
	int ch;
	while((ch = getch()) != KEY_F(1)) {
        /* FOR TESTING PRESSED CHAR
         * printw("%i", ch);
         */

        switch (ch) {
        case 267: // F3
            collections_flag = !collections_flag;

            if (!collections_flag) {
                destroy_win(collections);
                destroy_win(shell);
                destroy_win(documents);

                shell       = create_newwin(QTR_Y,
                                            MAX_X,
                                            ORIGIN_Y,
                                            ORIGIN_X);
                documents   = create_newwin(MAX_Y - QTR_Y,
                                            MAX_X,
                                            QTR_Y,
                                            ORIGIN_X);
            } else {
                reset_workspace();
            }
            break;
        }
    };
		
	endwin();
	return 0;
}
