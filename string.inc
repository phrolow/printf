BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; %s specifier
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    64-bit address in stack
; Exit:     -
; Destroys: rax, rcx, rdx, rsi, rdi
; Expects:  r8 for calculating stack arg offset
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string  push rbp
        mov rbp, rsp                ; stack frame

        mov rsi, [rbp + 32 + r8]    ; get arg

        xor rdx, rdx                ; length

.next:  cmp byte [rsi + rdx], 0     ; if current char is '\0'
        je .break

        inc rdx
        jmp .next

.break:
        mov rax, 1                  ; 1st syscall - write()

        syscall

        pop rbp
        ret