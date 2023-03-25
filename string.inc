BITS 64

string  push rbp
        mov rbp, rsp                ; stack frame

        mov rsi, [rbp + 32 + r8]    ; get arg

        xor rdx, rdx                ; length

.next:  cmp byte [rsi + rdx], 0           ; if current char is '\0'
        je .break

        inc rdx
        jmp .next

.break:
        mov rax, 1                  ; 1st syscall - write()

        syscall

        pop rbp
        ret