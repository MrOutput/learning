SECTION .data
	greeting DB `hello, world\n\0`

SECTION .text
GLOBAL _start
EXTERN print

_start:
	push rbp
	mov rbp, rsp

	push greeting
	call print
	add rsp, 8

	;exit
	mov rax, 60
	mov rdi, 0
	syscall
