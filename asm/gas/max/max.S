.section .data
	data_set: .quad 8, 1, 98, 18, 18, 12, 18, 19, 27, 32, 9, 12, 18, 92, 255, 0

.section .text
.globl _start


# rbx, data index
# rdi, current max
# rax, current data
_start:
	movq $0, %rbx # init index reg
	movq data_set(,%rbx,8), %rax
	movq %rax, %rdi

loop:	
	cmpq $0, %rax # check if end
	je exit
	incq %rbx
	movq data_set(,%rbx,8), %rax
	cmpq %rdi, %rax
	jle loop

	movq %rax, %rdi
	jmp loop

exit:
	movq $60, %rax
	syscall
