SECTION .text
    GLOBAL _start

    _start:
        ; print name
        mov rax,1     ; sys_write
        mov rdi,1     ; stdout
        mov rsi,name  ; start address of name
        mov rdx,nameLength ; length
        syscall

        ; exit program
        mov rax,60    ; sys_exit
        mov rdi,0     ; success
        syscall

SECTION .data
    name DB "Rafael Cepeda",10
    nameLength EQU $-name
