BITS 64

case_default    push rbp
                mov rbp, rsp

                sub rcx, 8      ; "put" arg back to stack
                dec rsi         ; we'll print '%'

                mov rax, 1
                mov rdx, 1

                syscall         ; write()

                pop rbp
                ret