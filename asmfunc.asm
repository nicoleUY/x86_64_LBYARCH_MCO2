;assembly part using x86-64

section .data
msg db "Hello World", 13, 10, 0		;13 10 is the \n

section .text
bits 64								;to tell 64 bits
default rel							;to support address relocation and relativity

									;above is standard part of template

global asmhello						;so that c can regognize, equivalent of extern
extern printf

asmhello:
	sub rsp, 8*5					;caller: if the assembly is caller we allocate stack pointer stack frame with 40 bytes
	lea rcx, [msg]
	call printf
	add rsp, 8*5					;adjust back the pointer
	ret


	;takeaway: first 4 params free, rcx, rdx, r8, r9. if more create stack frame and adjust