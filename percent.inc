BITS 64

percent:
    push rbp    
    mov rbp, rsp                ; stack frame

    add rcx, 8                  ; next arg
    mov rax, [rbp + 16 + rcx]   ; get next arg

    xor rdx, rdx
    mov dl, [rsi]              ; char after %

    cmp dl, 'b'
    call case_default
    jmp Return

    cmp dl, 'x'
    call case_default
    jmp Return

    call [rdx + call_table - 'b']

Return:
    pop rbp                     ; stack frame
    ret
; csdxob\%