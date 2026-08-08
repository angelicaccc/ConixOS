#include "cleark.h"
#include "drivers/vga.h"

void cleark(void) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            putchar(' ', x, y);
        }
    }
    kcusror_reset();
}