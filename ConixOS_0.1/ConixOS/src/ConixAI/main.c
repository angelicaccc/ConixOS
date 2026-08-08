#include "core/printk.h"
#include "core/stringk.h"
#include "drivers/keyboard.h"
#include "core/readlinek.h"
#include "core/cleark.h"
#include "init/main.h"

void ai_main() {
    char command[128];

    printk("Initialized ConixAI in kernel mode.");
    nlinek();

    while(1) {
        printk("ConixAI> ");
        readlinek(command, sizeof(command));

        if (strcmpk(command, "hello") == 0) {
            printk("Hello, I'm ConixAI. How can I help?");
            nlinek();
        } else if(strcmpk(command, "version") == 0) {
            printk("ConixAI version 0.1");
            nlinek();
        } else if (strcmpk(command, "exit") == 0) {
            printk("Leaving...");
            nlinek();
            kterminal_init();
        } else {
            printk("Unknown command: ");
            printk(command);
            nlinek();
        }
    }
}