BITS 64

case_default    push rbp
                mov rbp, rsp

                sub rcx, 8      ; "put" arg back to stack
                sub rsi, 1      ; we'll print '%'

                mov rax, 1
                mov rdx, 2

                syscall         ; write()

                pop rbp
                ret