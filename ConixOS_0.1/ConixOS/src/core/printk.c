#include "printk.h"

void printk(const char *str) {
    while (*str) {
        kputc(*str++);
    }
}

void nlinek(void) {
    kputc('\n');
}