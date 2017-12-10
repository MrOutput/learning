SECTION .text
;sysexit: equ 60
;
;global _start
;_start:
;        mov edi, 17
;        mov esi, 16
;        call calcsize
;
;exit:
;        mov eax, sysexit
;        xor edi, edi
;        syscall
;
; input
;     edi: dword size
;     esi: dword alignment
global calcsize
calcsize:
          xor edx,edx   ; unused for division
          mov eax, edi  ; set size
          div esi       ; divide by alignment
                        ; edx:eax / r/m32
                        ; result stored in eax <- quotient, edx <- remainder
          test edx, edx ; check if remainder
          jz .mul
          inc eax       ; inc if remainder

    .mul:
          mul esi       ; multiply by alignment
                        ; edx:eax <- eax * r/m32
          ret
