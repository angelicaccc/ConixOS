#include "cleark.h"
#include "kpanic.h"
#include "printk.h"

void kpanic(void) {
    cleark();

    printk("==== ConixOS Kernel Panic! ====");

    for (;;) {
        __asm__ volatile("hlt");
    }
}