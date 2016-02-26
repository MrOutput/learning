all: test

test: test.o
	ld -o test test.o

test.o: test.asm
	nasm -f elf64 test.asm

clean:
	rm *.o
	rm test
