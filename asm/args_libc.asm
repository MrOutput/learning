section .data
	format: db `%d: %s\n\0`

section .text
global _start
extern printf, exit

_start:
	mov rbp, rsp
	add rbp, 8

	mov r12, 0         ;index
	mov r13, [rbp - 8] ;argc
	
.loop:
	mov rdi, format
	mov rsi, r12
	mov rdx, [rbp + r12 * 8]
	call printf

	inc r12
	cmp r12, r13
	jl .loop

.done:
	mov rdi, 0
	call exit
