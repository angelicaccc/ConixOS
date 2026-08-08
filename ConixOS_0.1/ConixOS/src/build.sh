#!/bin/bash

set -e

echo "=========================="
echo "    Compiling ConixOS"
echo "=========================="

mkdir -p build
nasm -f elf32 ConixKernel_0.1/conixkernel/init/kernel_entry.asm -o build/kernel_entry.o
gcc -m32 -ffreestanding -I./ConixKernel_0.1 -c ConixKernel_0.1/conixkernel/drivers/vga.c -o build/vga.o -O2
gcc -m32 -ffreestanding -I./ConixKernel_0.1 -c ConixKernel_0.1/conixkernel/init/main.c -o build/kernel.o -O2
gcc -m32 -ffreestanding -I./ConixKernel_0.1 -c ConixKernel_0.1/conixkernel/drivers/keyboard.c -o build/keyboard.o -O2
gcc -m32 -ffreestanding -I./ConixKernel_0.1 -c ConixKernel_0.1/conixkernel/kernel/printk.c -o build/printk.o -O2
gcc -m32 -ffreestanding -I./ConixKernel_0.1 -c ConixKernel_0.1/conixkernel/kernel/stringk.c -o build/stringk.o -O2
ld -m elf_i386 -T linker.ld build/kernel_entry.o build/kernel.o build/vga.o build/keyboard.o build/stringk.o build/printk.o -o build/kernel.elf
mv build/kernel.elf iso/boot/kernel.elf