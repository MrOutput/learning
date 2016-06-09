SECTION .text
GLOBAL strlen

;r11 arg &char
;rdx cur char
;rsi source index
;RETURNS len of str
strlen:
	push rbp
	mov rbp, rsp

	mov r11, [rbp + 2 * 8] ;char*

	mov dl, [r11] ;init curchar
	mov rsi, 0

.compare:
	cmp dl, '\0'
	je .done

.next_byte:
	inc rsi
	mov dl, [r11 + rsi * 1]

.done:
	mov rax, rsi
	;inc rax

	mov rsp, rbp
	pop rbp
	ret
