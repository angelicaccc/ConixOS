#include "./conixkernel/drivers/vga.h"
#include "printk.h"

void printk(const char *str) {
    while (*str) {
        kputc(*str++);
    }
}