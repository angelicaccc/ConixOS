#include "cleark.h"
#include "kpanic.h"
#include "printk.h"

void kpanic(void) {
    cleark();

    printk("==== ConixOS Kernel Panic! ====\n");

    for (;;) {
        __asm__ volatile("hlt");
    }
}