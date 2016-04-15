section .text
	global _start

	_start: 
	print:	mov rax, 1
		mov rdi, 1
		mov rsi, digit
		mov rdx, 2
		syscall

		dec byte [digit]
		cmp byte [digit], '0'-1
		jnz print

	exit:	mov rax, 60
		mov rdi, 0
		syscall
section .data
	digit	db '9',`\n`
