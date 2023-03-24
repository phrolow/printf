BITS 64

printf: 
        push rbp
        mov rbp, rsp

        mov rdi, 1                      ; stdin
        mov r8, 16                     ; arg address counter

        mov rsi, [rbp + r8]              ; current char
        mov rbx, rsi                    ; rsi is begin of last substring, rbx is current char
        dec rbx                         ; loop will compensate it

.Next:
        inc rbx                         ; string iterator
        mov al, [rbx]                  ; current char
        cmp al, '%'                    ; stop on '%'
        jne .CheckEnd

        mov rdx, rbx                    ; calculate length of output
        sub rdx, rsi
        mov rax, 1                      ; 1st syscall (write)

        syscall

        call percent

        mov rsi, rbx                    ; new begin of substring
        add rsi, 2                         ; next char is begin of substr

.CheckEnd:
        cmp al, 0
        jne .Next

        mov rdx, rbx
        sub rdx, rsi                    ; calculate output length
        mov rax, 1                      ; 1st syscall (write)

        syscall

        mov rax, 0x60
        mov rdi, 0                      ; exit(0)
        
        syscall

        pop rbp
        ret

; nasm -f elf64 printf.asm -l a.lst
; ld -m elf_x86_64 printf.o -o printf