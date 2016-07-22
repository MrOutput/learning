.section .data
format:
	.asciz "Vendor ID: %s\n"

.section .bss
	.lcomm buf, 13

.section .text
.globl main

main:
	subq $8, %rsp

	xorq %rax, %rax
	cpuid

	movq $buf, %rax
	movl %ebx, buf
	movl %edx, 4(%rax)
	movl %ecx, 8(%rax)

	movq $0, 13(%rax)

	movq $format, %rdi
	movq $buf, %rsi
	call printf

	movq $0, %rdi
	call exit
