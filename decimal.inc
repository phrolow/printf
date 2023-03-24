BITS 64

decimal push rbp
        mov rbp, rsp                ; stack frame
        
        mov rax, [rbp + 32 + r8]     ; arg from printf call

        mov r9, 0x8000000000000000 ; bit mast 4 1st bit
        and r9, rax                 ; get sign
        shr r9, 0x3f               ; move bit to end

        cmp r9, 0
        je .skip_neg                ; if rax > 0, we don't need to neg it
        neg rax                      ; to unsigned

.skip_neg:
        mov rcx, 19                 ; num of chars in out
        mov rsi, buf                ; output buffer

.Next:  xor rdx, rdx

        mov rdi, 10

        div rdi

        add dl, '0'                 ; to char
        mov byte [rsi + rcx], dl    ; bit to buffer

        cmp rax, 0
        je .BreakLoop                   ; if our num lesser than r9, break loop

        loop .Next                      
.BreakLoop:
        mov rax, 1                  ; 1st syscall - write()
        add rsi, rcx                ; start output from last non-zero digit
        mov rdx, 23                 ; length of write()
        sub rdx, rcx                ; length of output

        cmp r9, 1
        jne .skip_minus

        dec rsi
        inc rdx
        mov byte [rsi], '-'

.skip_minus:
        mov rdi, 1                  ; stdout

        syscall

        pop rbp
        ret
