BITS 64

;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Custom realisation of std::printf
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    _cdecl
; Exit:     -
; Destroys: -
; Expects:  -
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

global _printf

section .text
    %include "printf.inc"

    _printf:
        push r9         			
        push r8         
        push rcx        
        push rdx        
        push rsi	    
        push rdi

        push rbp

        call printf

        pop rbp

        pop rdi        
        pop rsi        
        pop rdx       
        pop rcx      
        pop r8         
        pop r9  

        ret

section .data
    buf db 0x100 dup(0)

section .rodata
    
jmp_table:
    dq binary                           ; %b
    dq char                     ; %c
    dq decimal                          ; %d
    dq 'o' - 'd' - 1 dup(case_default)
    dq octal                            ; %o
    dq 's' - 'o' - 1 dup(case_default)
    dq string                           ; %s
    dq 'x' - 's' - 1 dup(case_default)
    dq hex                              ; %x