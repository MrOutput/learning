SECTION .text
    GLOBAL _start

    _start:
    mov bl,0 ; set exit flag off

    ; print letter
    .print:
        mov rax,1      ; sys_write
        mov rdi,1      ; stdout
        mov rsi,letter ; start address of name
        mov rdx,1      ; length
        syscall
        cmp bl,1       ; is exit flag on
        jz .exit      ; exit if exit flag is set

        inc word [letter]     ; increment letter value
        cmp word [letter],512 ; compare letter value to 255 (max ascii value)
        jb .print             ; if letter value is less than 255, print another letter

        ; loop
        mov word [letter],10 ; set letter to newline char
        mov bl,1             ; set exit flag
        jmp .print           ; print letter

    ; exit program
    .exit:
        mov rax,60    ; sys_exit
        mov rdi,0     ; success
        syscall

SECTION .data
    letter DW 0H
