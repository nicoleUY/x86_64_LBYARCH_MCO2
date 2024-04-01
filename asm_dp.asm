; Gene Cedric D. Alejo and Nicole Kate T. Uy - S12

section .text
bits 64
default rel
global dot_product_asm

dot_product_asm:
    xorps xmm0, xmm0    ; Initializing sum to zero

.loop:
    movss xmm1, [rcx]   ; Load a[i] into xmm1
    movss xmm2, [rdx]   ; Load b[i] into xmm2
    mulss xmm1, xmm2    ; Multiply a[i] and b[i]
    addss xmm0, xmm1    ; Add the product to the sum
    add rcx, 4          ; Move to the next element of a
    add rdx, 4          ; Move to the next element of b
    dec r8             ; Decrement the counter
    jnz .loop           ; If counter is not zero, loop again

    ret
