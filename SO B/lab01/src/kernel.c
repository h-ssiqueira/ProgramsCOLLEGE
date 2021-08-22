#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "driver.h"
/*
To compile:
* Comment the pre processor directives and run the command below:
i686-linux-gnu-gcc-10 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
*/

/* Check if the compiler thinks you are targeting the wrong operating system. */
/*
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
*/

/* This tutorial will only work for the 32-bit ix86 targets. */
/*
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
*/

void kernel_main(void){
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	terminal_writestring("Hello, I'm a simple kernel!\n");
	/* Get the value of each key of keyboard */
	while(true)
		terminal_putchar(translate(inb(0x60)));
}