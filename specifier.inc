BITS 64

specifier:
    push rbp    
    mov rbp, rsp                ; stack frame

    add r8, 8                  ; next arg

    xor rdx, rdx
    mov dl, [rbx + 1]               ; char after %

    cmp dl, '%'                 ; if %% specifier
    jne .not_percent            ; '%' too far from letters

    call percent
    jmp .return

.not_percent:
    cmp dl, 'b'                 ; if char lesser than 'b' - fisrt value in our range
    jae .if_char_too_big

    call case_default
    jmp .return                 ; directly to end of "specifier"

.if_char_too_big:
    cmp dl, 'x'
    jbe .format_out              ; if char bigger than 'x' - last value in our range

    call case_default
    jmp .return

.format_out:
    call [jmp_table + (rdx - 'b') * 8]

.return:

    pop rbp                     ; stack frame
    ret
; csdxob\%
    
jmp_table:
    dq binary                           ; %b
    dq char                     ; %c
    dq decimal                          ; %d
    dq 'o' - 'd' - 1 dup(case_default)
    dq octal                            ; %o
    dq 'x' - 'o' - 1 dup(case_default)
    dq hex                              ; %x