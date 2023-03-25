BITS 64
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Wrong specifier
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
; Entry:    -
; Exit:     corrected r8 - cause we actually don't need stack arg
; Destroys: -
; Expects:  -
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
case_default    sub r8, 8      ; "put" arg back to stack

                ret