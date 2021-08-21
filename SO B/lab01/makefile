CC = i686-linux-gnu-gcc-10
CCa = i686-linux-gnu-as
CFLAGS = -c -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc

###############################################################
all: bin myos.iso

bin:
	mkdir -p bin

boot.o : src/boot.s
	${CCa} src/boot.s -o bin/boot.o

kernel.o : src/kernel.c
	${CC} src/kernel.c -o bin/kernel.o ${CFLAGS}

myos.bin : src/linker.ld boot.o kernel.o
	${CC} -T src/linker.ld -o bin/myos.bin bin/boot.o bin/kernel.o ${LDFLAGS}

myos.iso : myos.bin
	mkdir -p isodir/boot/grub
	cp bin/myos.bin isodir/boot/myos.bin
	cp src/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

################################################################
clean:
	rm -rf bin/*.o