#include "printk.h"

void printk(const char *str) {
    while (*str) {
        kputc(*str++);
    }
}