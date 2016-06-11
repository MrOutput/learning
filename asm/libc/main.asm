SECTION .data
greeting: DB `hello, world\0`

SECTION .text
GLOBAL _start
EXTERN puts
EXTERN exit

;SysV Calling Convention
_start: mov rdi,  greeting
	call puts
	add rsp, 8

	mov rdi, 0
	call exit
