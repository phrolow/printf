BITS 64

percent         sub r8, 8      ; "put" arg back to stack

                mov rax, 1          ; 1st syscall - write()
                mov rdx, 1          ; length
                mov rsi, buf
                mov [rsi], byte '%' ; '%' to buf
                mov rdi, 1          ; stdout descriptor

                syscall             ; write percent

                ret