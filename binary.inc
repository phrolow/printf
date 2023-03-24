BITS 64

binary  push rbp
        mov rbp, rsp                ; stack frame
        
        mov r9, [rbp + 32 + r8]     ; arg from printf call

        mov rcx, 0x40               ; num of chars in out (I'll fix zeros in start)
        mov rsi, buf                ; output buffer

.Next:  mov rdx, 0x8000000000000000                   ; rdx will be current bit

        dec rcx                 
        shr rdx, cl		            ; set current bit
        mov rax, rdx                        ; rax is power of 2, matching current bit. If rax is bigger than num, loop will be broken

        and rdx, r9		            ; get current bit of ax

        inc rcx			            ; restore rcx

        rol rdx, cl                 ; bit to last digit

        add dl, '0'                 ; to char
        mov byte [rsi + rcx - 1], dl    ; bit to buffer

        cmp rax, r9
        ja .BreakLoop                   ; if our num lesser than rax, break loop

        loop .Next                      
.BreakLoop:
        mov rax, 1                  ; 1st syscall - write()
        mov rdx, 0x40               ; length of write()
        add rsi, rcx                ; start output from last non-zero digit
        mov rdx, 0x40
        sub rdx, rcx                ; length of output

        syscall

        pop rbp
        ret
