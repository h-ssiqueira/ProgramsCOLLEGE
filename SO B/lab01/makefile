CC = i686-linux-gnu-gcc-10
CCa = i686-linux-gnu-as
CFLAGS = -c -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T -ffreestanding -O2 -nostdlib -lgcc

###############################################################
all: myos.iso

boot.o : boot.s
	${CCa} boot.s -o boot.o

kernel.o : kernel.c
	${CC} kernel.c -o kernel.o ${CFLAGS}

myos.bin : linker.ld boot.o kernel.o
	${CC} linker.ld -o myos.bin boot.o kernel.o ${LDFLAGS}

myos.iso : myos.bin
	mkdir -p isodir/boot/grub
	cp myos.bin isodir/boot/myos.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

################################################################
clear:
	rm -rf *.o