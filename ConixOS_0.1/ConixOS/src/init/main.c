#include "core/printk.h"
#include "core/stringk.h"
#include "drivers/keyboard.h"
#include "core/readlinek.h"
#include "core/cleark.h"
#include "core/kpanic.h"
#include "ConixAI/main.h"
#include "core/kpanict.h"

void kterminal_init() {
    printk("ConixKernel Terminal Initialized.");
    nlinek();

    unsigned char scancode = keyboard_read();

    char command[128];

    while (1) {
        printk("> ");
        readlinek(command, sizeof(command));

        if (strcmpk(command, "clear") == 0) {
            cleark();
        } else if (strcmpk(command, "panic") == 0) {
            kpanic_test();
      } else if (strcmpk(command, "help") == 0) {
            printk("Available commands:");
            nlinek();
            printk("  clear - Clear the screen");
            nlinek();
            printk("  panic - Test kernel panic from system");
            nlinek();
            printk("  help - Show this help message");
            nlinek();
            printk("  conixai - Run ConixAI in kernel mode");
            nlinek();
        } else if (strcmpk(command, "conixai") == 0) {
            ai_main();
        } else {
            printk("Unknown command: ");
            printk(command);
            nlinek();
        }
    }
}

void kernel_main() {

    printk("Hello, ConixKernel!");
    nlinek();

    printk("Press F5 to enter to the kernel terminal.");
    nlinek();
    
    while (1) {
        unsigned char scancode = keyboard_read();

        if (scancode == 0) {
            continue;
        }

        if (scancode & 0x80)
            continue;
        
        if (scancode == 0x3F) {
            nlinek();
            kterminal_init();
            break;
        }
    }
}
