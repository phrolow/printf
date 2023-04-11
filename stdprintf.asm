global main

extern printf
BITS 64

main:
	push    rbp
	mov     rbp, rsp

    sub     rsp, 8
    push    6
    mov     r9,  5
    mov     r8,  4
    mov     rcx, 3
    mov     rdx, 2
	mov     rsi, 228
	lea     rdi, Msg
	call    printf

    add     rsp, 16

	mov     rax, 0x3c
    xor     rdi, rdi
    syscall


section .data

Msg: db "%d %d %d %d %d %d", 0xa, 0x00