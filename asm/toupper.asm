;learning program 
;converts lowercase
;to uppercase
;
section .data
message: db `Hello, World!\n`
message.length equ $-message

section .text
global _start

sys_write equ 1
stdout equ 1
sys_exit equ 60
exit_success equ 0
lower_bound equ 97
upper_bound equ 122
offset equ 32

_start:
	mov rax, sys_write
	mov rdi, stdout
	mov rsi, message
	mov rdx, message.length
	call toupper
	syscall

	mov rax, sys_exit
	mov rdi, exit_success
	syscall

;non-standard calling convention
;
;ARGS
;rsi char*
;rdx len
;VARS
;rcx index
toupper:
	push rcx
	mov rcx, 0

.loop:
	cmp byte [rsi + rcx * 1], lower_bound
	jl .next
	cmp byte [rsi + rcx * 1], upper_bound
	jg .next

	sub byte [rsi + rcx * 1], offset

.next:
	inc rcx
	cmp rcx, rdx
	je .done
	jmp .loop

.done:
	pop rcx
	ret
