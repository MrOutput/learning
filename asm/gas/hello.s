.section .data
	greet: .ascii "hello, world\n"

.section .text
.globl _start

_start:
	mov $1, %rax
	mov $1, %rdi
	mov $greet, %rsi
	mov $13, %rdx
	syscall

	mov $60, %rax
	mov $0, %rdi
	syscall
