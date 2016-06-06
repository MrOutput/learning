; prints argc

SECTION .data
buf: DB ` \n`
BUF_LEN		EQU 2

SECTION .text
GLOBAL _start

SYS_WRITE	EQU 1
SYS_EXIT	EQU 60
EXIT_SUCCESS	EQU 0
STDOUT		EQU 1
ITOA_OFFSET	EQU '0'

_start: mov rax, [rsp]
	mov byte [buf], al ;move argc into buffer

print:	mov rax, SYS_WRITE
	mov rdi, STDOUT
	mov rsi, buf
	add qword [rsi], ITOA_OFFSET
	mov rdx, BUF_LEN
	syscall

exit:	mov rax, SYS_EXIT
	mov rdi, EXIT_SUCCESS
	syscall
