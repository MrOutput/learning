SECTION .data
greeting: DB `hello, world\0`
format: DB `Len: %d\n`

SECTION .text
EXIT_SUCCESS EQU 0
GLOBAL _start
EXTERN puts
EXTERN strlen
EXTERN exit
EXTERN printf

;SysV Calling Convention
_start:	mov rdi,  greeting
	call puts

	mov rdi, greeting
	call strlen

	mov rsi, rax
	mov rdi, format
	call printf

	mov rsi, EXIT_SUCCESS
	call exit
