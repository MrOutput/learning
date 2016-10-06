;read line from stdin
;transform msg to upper case
;print message
;repeat

%define BUF_SZ 2048
%define OFFSET 20H

SECTION .text
GLOBAL _start

_start:
	mov rdi, prompt
	mov rsi, 2
	call print

	;read line
	xor rax, rax
	xor rdi, rdi
	mov rsi, buf
	mov rdx, BUF_SZ
	syscall

	cmp rax, 0
	je exit

	cmp rax, 1
	je _start

	push rax
	mov rdi, buf
	mov rsi, rax
	call toupper
	pop rax

	mov rdi, buf
	mov rsi, rax
	call print
	

	jmp _start

exit:
	push qword 0AH
	mov rdi, rsp
	mov rsi, 1
	call print
	pop rax

	mov rax, 60
	xor rdi, rdi
	syscall

;void print(void *, size_t)
print:
	mov rdx, rsi
	mov rsi, rdi
	mov rdi, 1
	mov rax, 1
	syscall
	ret

;void toupper(void *buf, int size)
toupper:
	xor rcx, rcx

.loop:
	mov al, byte [rdi + rcx]

	cmp al, 'a'
	jl .next
	cmp al, 'z'
	jg .next

	sub al, OFFSET
	mov byte [rdi + rcx], al

.next:
	inc rcx
	cmp rcx, rsi
	jl .loop

	ret



SECTION .data
prompt: db "> "


SECTION .bss
buf: resb BUF_SZ
