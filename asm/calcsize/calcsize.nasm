SECTION .text
; inputs
;     edi: dword size
;     esi: dword alignment
; output
;     eax: dword aligned
global calcsize
calcsize:
          xor edx, edx  ; unused for division
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
