;assembly part using x86-64

section .data
msg db "Hello World", 13, 10, 0		;13 10 is the \n

section .text
bits 64								;to tell 64 bits
default rel							;to support address relocation and relativity

									;above is standard part of template

;global asmhello						;so that c can regognize, equivalent of extern
global summ
extern printf

;asmhello:
;	sub rsp, 8*5					;caller: if the assembly is caller we allocate stack pointer stack frame with 40 bytes
;	lea rcx, [msg]
;	call printf
;	add rsp, 8*5					;adjust back the pointer
;	ret

summ:
	push rsi
	push rbp
	mov rbp, rsp
	add rbp, 16						; return address of call and push rbp
	add rbp, 8
		xor rax, rax
		mov eax, ecx				;1st param in rcx
		add eax, edx				;2nd param in rdx, ans return in rax
		add eax, r8d				;3rd param in r8
		add eax, r9d				;4th param in r9
		mov esi, [rbp+32]			;5th param
		add eax, esi				
		mov esi, [rbp+40]			;6th param
		add eax, esi				;return in eax
		mov esi, [rbp+48]			;7th param
		add eax, esi				;return in eax

	pop rbp
	pop rsi
	ret

	;takeaway: first 4 params free, rcx, rdx, r8, r9. if more create stack frame and adjust