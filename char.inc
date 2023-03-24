BITS 64

char    push rbp    ; stack frame
        mov rbp, rsp

        mov rax, [rbp + 32 + r8]    ; arg from printf call

        mov rsi, buf                ; buf in write()
        mov [rsi], al               ; store our char
        mov rax, 1                  ; 1st syscall - write()
        mov rdx, 1                  ; length
        
        syscall

        pop rbp
        ret