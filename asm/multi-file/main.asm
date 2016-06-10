SECTION .data
	greeting DB `hello, world\n\0`

SECTION .text
GLOBAL _start
EXTERN print
EXTERN exit

_start:
	push rbp
	mov rbp, rsp

	push greeting
	call print
	add rsp, 8

	push 0
	call exit
