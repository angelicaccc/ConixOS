#include "conixkernel/kernel/printk.h"
#include "conixkernel/kernel/stringk.h"
#include "conixkernel/drivers/keyboard.h"

void kernel_main() {
    printk("Hello, ConixKernel!\n");
    
    while (1) {
        __asm__ __volatile__("hlt");
    }
}
