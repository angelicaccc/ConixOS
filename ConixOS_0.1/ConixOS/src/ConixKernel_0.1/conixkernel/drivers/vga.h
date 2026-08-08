#ifndef VGA_H
#define VGA_H
#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define WHITE_ON_BLACK 0x0F

extern char *video_memory;
void putchar(char c, int col, int row);
void kputc(char c);

#endif