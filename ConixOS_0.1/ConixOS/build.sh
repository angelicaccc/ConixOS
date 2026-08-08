#!/bin/bash

set -e

echo "=========================="
echo "    Compiling ConixOS"
echo "=========================="

mkdir -p build
nasm -f elf32 src/init/kernel_entry.asm -o build/kernel_entry.o
gcc -m32 -ffreestanding -Isrc -c src/drivers/vga.c -o build/vga.o -O2
gcc -m32 -ffreestanding -Isrc -c src/init/main.c -o build/kernel.o -O2
gcc -m32 -ffreestanding -Isrc -c src/drivers/keyboard.c -o build/keyboard.o -O2
gcc -m32 -ffreestanding -Isrc -c src/core/printk.c -o build/printk.o -O2
gcc -m32 -ffreestanding -Isrc -c src/core/stringk.c -o build/stringk.o -O2
ld -m elf_i386 -T src/linker.ld build/kernel_entry.o build/kernel.o build/vga.o build/keyboard.o build/stringk.o build/printk.o -o build/kernel.elf
mv build/kernel.elf iso/boot/kernel.elf
grub2-mkrescue -o "ConixOS 0.1_2026.iso" iso
