CC = i686-linux-gnu-gcc-10
CCa = i686-linux-gnu-as
CFLAGS = -c -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc

###############################################################
all: bin myos.iso

# Folder for binaries
bin:
	mkdir -p bin

boot.o : src/boot.s
	${CCa} src/boot.s -o bin/boot.o

drivers : src/video.c src/keyboard.c
	${CC} src/video.c -o bin/video.o ${CFLAGS}
	${CC} src/keyboard.c -o bin/keyboard.o ${CFLAGS}

kernel.o : src/kernel.c
	${CC} src/kernel.c -o bin/kernel.o ${CFLAGS}

myos.bin : src/linker.ld boot.o kernel.o drivers
	${CC} -T src/linker.ld -o bin/myos.bin bin/*.o ${LDFLAGS}

myos.iso : myos.bin
	mkdir -p isodir/boot/grub
	cp bin/myos.bin isodir/boot/myos.bin
	cp src/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir
	qemu-system-x86_64 -boot d -cdrom myos.iso -m 32
# sudo apt install qemu-system-x86

################################################################
clean:
	rm -rf bin/*.o