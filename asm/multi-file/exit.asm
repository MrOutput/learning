SYS_EXIT EQU 60

SECTION .text
GLOBAL exit

; arg exit status
exit:
	mov rax, SYS_EXIT
	mov rdi, [rsp + 8]
	syscall
