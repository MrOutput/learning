;prints argc

SECTION .data
buf db ` \n`
; nothing here yet

SECTION .text
GLOBAL _start

SYS_WRITE	EQU 1
SYS_EXIT	EQU 60
EXIT_SUCCESS	EQU 0
STDOUT		EQU 1
ITOA_OFFSET	EQU '0'

_start:	mov rax, [rsp]	;move argc
	mov rbp, rsp		;new stack frame

	push rax		;int arg for itoa
	call itoa
	add rsp, 8		;clean arg off stack

	mov rdx, [rax]		;save char len in rdx for printing
	inc rax			;increment addres to start of char array
	mov rsi, rax		;move char address into rsi for prnting

print:	mov rax, SYS_WRITE
	mov rdi, STDOUT
	syscall

exit:	mov rax, SYS_EXIT
	mov rdi, EXIT_SUCCESS
	syscall

;char* itoa(int)
;return a pointer to chars
;stores length of chars in first byte
itoa:	push rbp
	mov rbp, rsp		; new stack frame

	mov rax, [rbp + 2 * 8]	;int arg into rax
	add rax, ITOA_OFFSET

	mov rsp, rbp
	pop rbp
	ret
