BITS 64

global _start

section .text
    %include "binary.inc"
    %include "default.inc"
    %include "percent.inc"
    %include "printf.inc"

    _start:
        mov rax, msg

        push 13
        push rax

        call printf

        mov rax, 60
        mov rdi, 0
        syscall

section .data
    msg db "%c", 0xa, "kirilla", 0xa, 0x0
    buf db 0x100 dup(0)
