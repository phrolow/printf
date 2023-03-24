BITS 64

octal   push rbp
        mov rbp, rsp                ; stack frame
        
        mov r9, [rbp + 32 + r8]     ; arg from printf call

        mov rcx, 22                 ; num of chars in out
        mov rsi, buf                ; output buffer

.Next:  mov rdx, 7                   ; rdx will be current num

        and rdx, r9                 ; get r9 % 8
        shr r9, 3                  ; r9 / 8

        add dl, '0'                 ; to char
        mov byte [rsi + rcx], dl    ; bit to buffer

        cmp r9, 0
        je .BreakLoop                   ; if our num lesser than rax, break loop

        loop .Next                      
.BreakLoop:
        mov rax, 1                  ; 1st syscall - write()
        add rsi, rcx                ; start output from last non-zero digit
        mov rdx, 23                 ; length of write()
        sub rdx, rcx                ; length of output

        syscall

        pop rbp
        ret
