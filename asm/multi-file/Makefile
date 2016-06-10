default:
	nasm -f elf64 exit.asm
	nasm -f elf64 main.asm
	nasm -f elf64 print.asm
	nasm -f elf64 strlen.asm

	ld -s strlen.o print.o exit.o main.o

clean:
	rm *.o
	rm a.out
