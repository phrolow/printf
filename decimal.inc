BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; %d specifier
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    32-bit int in stack
; Exit:     -
; Destroys: rax, rcx, rdx, rsi, rdi, r9
; Expects:  r8 for calculating stack arg offset
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

decimal push rbp
        mov rbp, rsp                ; stack frame
        
        mov eax, [rbp + 32 + r8]    ; arg from printf call

        mov r9d, 0x80000000         ; bit mask for 1st bit
        and r9d, eax                ; get sign
        shr r9d, 0x1f               ; move bit to end

        cmp r9d, 0
        je .skip_neg                ; if eax > 0, we don't need to neg it
        neg eax                     ; to unsigned

.skip_neg:
        mov rcx, 19                 ; num of chars in out
        mov rsi, buf                ; output buffer

.Next:  xor rdx, rdx

        mov rdi, 10

        div rdi

        add dl, '0'                 ; to char
        mov byte [rsi + rcx], dl    ; bit to buffer

        cmp eax, 0
        je .BreakLoop                   ; if our num lesser than r9d, break loop

        loop .Next                      
.BreakLoop:
        mov rax, 1                  ; 1st syscall - write()
        add rsi, rcx                ; start output from last non-zero digit
        mov rdx, 23                 ; length of write()
        sub rdx, rcx                ; length of output

        cmp r9d, 1
        jne .skip_minus

        dec rsi
        inc rdx
        mov byte [rsi], '-'

.skip_minus:
        mov rdi, 1                  ; stdout

        syscall

        pop rbp
        ret
