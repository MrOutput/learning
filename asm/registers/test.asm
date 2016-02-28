SECTION .text
    GLOBAL _start

    _start:
        mov al,8
        mov bx,4
        mov bl,1

        ; exit program
        .exit:
            mov rax,60    ; sys_exit
            mov rdi,0     ; success
            syscall
