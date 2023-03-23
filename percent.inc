BITS 64

percent:
    push rbp    
    mov rbp, rsp                ; stack frame

    add rcx, 8                  ; next arg
;    mov rax, [rbp + 16 + rcx]   ; get next arg

    xor rdx, rdx
    mov dl, [rsi]               ; char after %

    cmp dl, 'b'
    call case_default
    jmp Return

    cmp dl, 'x'
    call case_default
    jmp Return

    call [jmp_table + (rdx - 'b')]

Return:
    inc rsi

    pop rbp                     ; stack frame
    ret
; csdxob\%
    
jmp_table:
    dq case_default                     ; %b
    dq case_default                     ; %c
    dq case_default                     ; %d
    dq 'x' - 'd' - 1 dup(case_default)  ; other %