BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; %c specifier
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    char in stack as last byte
; Exit:     -
; Destroys: rax, rdx, rsi
; Expects:  r8 for calculating stack arg offset
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char    push rbp                        ; stack frame
        mov rbp, rsp

        mov rax, [rbp + 32 + r8]        ; arg from printf call

        mov rsi, buf                    ; buf in write()
        mov [rsi], al                   ; store our char
        mov rax, 1                      ; 1st syscall - write()
        mov rdx, 1                      ; length
        
        syscall

        pop rbp
        ret