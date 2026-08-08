#include "cleark.h"
#include "printk.h"
#include "printk.h"
#include "drivers/keyboard.h"

void kpanic_test(void) {
    
    cleark();

    printk("==== ConixOS Kernel Panic Test ====");
    nlinek();
    printk("Press ESC to exit to the test.");
    nlinek();

    while(1) {

        unsigned char scancode = keyboard_read();

        if (scancode == 0)
            continue;

        if (scancode & 0x80)
            continue;

        if (scancode == 0x01) {
            return;
        }
    } 
}