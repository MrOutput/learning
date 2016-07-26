section .data
sys_exit: equ 60
exit_failure: equ 1

section .text
global _start

_start: mov r11, exit_failure
	xor rdi, rdi 
	cmp qword [rsp], r11
	cmove rdi, r11

	mov rax, sys_exit
	syscall
