section .data
message: db `hello, world\n`

section .text
global _start

_start:	mov rcx, 10

loop:	push rcx
	call print
	pop rcx
	loop loop

exit:	mov rax, 60
	mov rdi, 0
	syscall

print:	mov rax, 1
	mov rdi, 1
	mov rsi, message
	mov rdx, 13
	syscall
	ret
