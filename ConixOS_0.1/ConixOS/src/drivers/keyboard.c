#include "keyboard.h"
#include "io.h"

unsigned char keyboard_read(void) {
    if((inb(KEYBOARD_STATUS_PORT) & 1) == 0) 
        return 0;

    return inb(KEYBOARD_DATA_PORT);
}