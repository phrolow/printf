BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; %% specifier
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    -
; Exit:     fixed r8
; Destroys: rax, rdx, rsiW
; Expects:  r8 for calculating stack arg offset
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

percent         sub r8, 8           ; "put" arg back to stack

                mov rax, 1          ; 1st syscall - write()
                mov rdx, 1          ; length
                mov rsi, buf
                mov [rsi], byte '%' ; '%' to buf

                syscall             ; write percent

                ret