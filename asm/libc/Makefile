default:
	nasm -f elf64 main.asm
	ld -s main.o -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	rm -f *.o a.out
