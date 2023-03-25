BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; '%' handler
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    rbx - pointer to current char
; Exit:     Modified r8 (points at next stack arg)
; Destroys: rax, rcx, rdx, rsi, rdi, r9
; Expects:  -
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

specifier:
    push rbp    
    mov rbp, rsp                ; stack frame

    add r8, 8                   ; next arg

    cmp r8, 72
    jne .not_printf_address     ; if r8 points at printf call

    add r8, 8

.not_printf_address:
    xor rdx, rdx
    mov dl, [rbx + 1]           ; char after %

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
    jbe .format_out             ; if char bigger than 'x' - last value in our range

    call case_default
    jmp .return

.format_out:
    call [jmp_table + (rdx - 'b') * 8]  ; calculate address of call

.return:

    pop rbp                     ; stack frame
    ret
; csdxob\%