#include "vga.h"

char *video_memory = (char *)VGA_ADDRESS;
static int cursor_x = 0;
static int cursor_y = 0;

void putchar(char c, int col, int row) {

    if (col >= VGA_WIDTH || row >= VGA_HEIGHT) {
        return;
    }

    static int position = 0;
    video_memory[position * 2] = c;
    video_memory[position * 2 + 1] = WHITE_ON_BLACK;

    position++;
}

void kputc(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        putchar(c, cursor_x, cursor_y);
        cursor_x++;
    }

    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= VGA_HEIGHT) {
        cursor_x = 0;
        cursor_y = 0;
    }
}