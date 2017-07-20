; BUILD WITH
;   nasm -f elf64 main.asm
;   ld -s main.o -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
;
section .data
	fmt: db `%d: %s\n\0`

section .text
global _start
extern printf, exit

_start:
	mov r13, [rsp] ;argc
	lea rbx, [rsp + 8]   ;add dword for int, and dword for pad (8-byte alignment)

	mov r12, 0     ;index
; do-while loop
loop:
	mov rdi, fmt   ; set fmt str
	inc r12        ; i+1
	mov rsi, r12
	mov rdx, [rbx]
	call printf
	add rbx, 8     ; point to next el
	cmp r12, r13   ; loop condit
	jl loop

	xor rdi, rdi
	call exit
