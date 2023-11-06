#include <ncurses.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159

void drawWave(int row, int col, int amplitude, int frequency, int phase) {
    for (int i = 0; i < col; i++) {
        int x = amplitude * sin(2 * PI * frequency * i / col + phase);
        mvprintw(row + x, i, "O");
    }
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);

    int row, col;
    getmaxyx(stdscr, row, col);

    int amplitude = 5; // Adjust this value to increase the size of the wave
    int frequency = 5;
    int phase = 0;

    while (1) {
        clear();
        drawWave(row / 2, col, amplitude, frequency, phase);
        refresh();
        phase++;
        usleep(100000); // Adjust this value to change the animation speed
    }

    endwin();
    return 0;
}
