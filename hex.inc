BITS 64

hex     push rbp
        mov rbp, rsp                ; stack frame
        
        mov r9, [rbp + 32 + r8]     ; arg from printf call

        mov rcx, 0x10               ; num of chars in out 
        mov rsi, buf                ; output buffer

.Next:  mov rdx, 0xF000000000000000                 ; rdx will be current 4 bits

        dec rcx
        shl rcx, 2         
        shr rdx, cl		            ; set current bit, is "shr rdx, cl * 4"
        mov rax, rdx                ; rax is power of 2, matching current bit. If rax is bigger than num, loop will be broken

        and rdx, r9		            ; get current bit of ax

        add cl, 4
        rol rdx, cl                 ; bit to last digit
        shr rcx, 2                  ; is "rol rdx, 4 * (cl + 1)"

        add dl, '0'                 ; to char

        cmp dl, '9'
        jbe .to_buf                 ; if char must be letter

        add dl, 'a' - '0' - 0xa     ; to letter

.to_buf:
        mov byte [rsi + rcx], dl    ; bit to buffer

        cmp rax, r9
        ja .BreakLoop                   ; if our num lesser than rax, break loop

        loop .Next                      
.BreakLoop:
        mov rax, 1                  ; 1st syscall - write()
        add rsi, rcx                ; start output from last non-zero digit
        mov rdx, 0x11               ; length of write()
        sub rdx, rcx                ; length of output

        syscall

        pop rbp                     ; stack frame
        ret
