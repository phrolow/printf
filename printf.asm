BITS 64


global _start

section .text
    %include "printf.inc"
    %include "percent.inc"
    %include "default.inc"

    _start:
        mov rax, msg

        push rax

        call printf

        mov rax, 60
        mov rdi, 0
        syscall

section .data
    msg db "ochko %kirilla", 0xa, 0x0
    
call_table:
    dw case_default
    dw case_default
    dw case_default
    dw 'x' - 'd' - 1 dup(case_default)
