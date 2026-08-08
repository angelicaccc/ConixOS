#include "readlinek.h"
#include "drivers/keyboard.h"
#include "drivers/vga.h"

void readlinek(char *buffer, unsigned int size) {
    unsigned int index = 0;
    while (1) {
        unsigned char scancode = keyboard_read();

        if (scancode == 0)
            continue;

        if (scancode & 0x80)
            continue;

        char c = keyboard_scancode_to_ascii(scancode);

        if (c ==0)
            continue;

        if (c == '\n') {
            buffer[index] = '\0';
            kputc('\n');
            return;
        }

        if (c == '\b') {
            if (index > 0) {
                index--;
                buffer[index] = '\0';
                kputc('\b');
            }

            continue;
        }

        if(index >= size - 1)
            continue;

        buffer[index++] = c;
        buffer[index] = '\0';
        kputc(c);
    }
}