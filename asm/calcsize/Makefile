default:
	nasm -f elf64 calcsize.nasm
	cc mine.c calcsize.o -O2 -s
clean:
	rm a.out calcsize.o
observe:
	cc mine.c calcsize.o -O2 -S
