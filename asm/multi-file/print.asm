STDOUT EQU 1
SYS_WRITE EQU 1

SECTION .text
GLOBAL print
EXTERN strlen

; prints to stdout
; print(char*)
print:
	push rbp
	mov rbp, rsp

	mov rsi, [rbp + 2 * 8] ;load &char

	push rsi ;char* arg
	call strlen
	add rsp, 8

	mov rdx, rax ;set size from ret val
	mov rax, SYS_WRITE
	mov rdi, STDOUT
	syscall

	mov rsp, rbp
	pop rbp
	ret
