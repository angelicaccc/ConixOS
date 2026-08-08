#include "keyboard.h"
#include "io.h"

const char scancode_to_ascii[128] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
  '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0,  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',   0,
 '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0, '*',   0,
};

char keyboard_read(void) {
    if((inb(KEYBOARD_STATUS_PORT) & 0x01) == 0) {
        return 0;
    }

    unsigned char scancode = inb(KEYBOARD_DATA_PORT);

    if (scancode & 0x80) {
        return 0;
    }

    if (scancode < sizeof(scancode_to_ascii)) {
        return scancode_to_ascii[scancode];
        
    }

    return 0;
}