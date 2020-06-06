#include <curses.h>
#include <string.h>

/* defines */
#define EDITOR "tedit"
#define VERSION "v0.1"

#define KEY_ESCAPE 27


/* Draw the header and move the cursor to (1,0) */
void draw_header(const char *filename)
{
    attron(A_STANDOUT);
    int name_len = COLS/2 - (strlen(EDITOR) + strlen(VERSION) + 1);
    printw("%s %s %*s", EDITOR, VERSION, name_len, filename);
    printw("%*s", COLS/2, "");
    attroff(A_STANDOUT);
}

int main(int argc, char *argv[])
{

    char *filename;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    if(argv[1])
        filename = argv[1];
    else
        filename = "New Buffer";

    draw_header(filename);


    /* Need to move the cursor with arrow keys */

    int key;
    int position_x = 0;
    int position_y= 1;

    while(1)
    {
        move(position_y, position_x);
        key = getch();
        switch(key)
        {
            case KEY_UP:
                if(position_y > 1)
                    position_y--;
                break;
            case KEY_DOWN:
                if(position_y < LINES - 1)
                    position_y++;
                break;
            case KEY_LEFT:
                if(position_x > 0)
                    position_x--;
                break;
            case KEY_RIGHT:
                if(position_x < COLS - 1)
                    position_x++;
                break;
        }
    }
    endwin();
    return 0;
}
