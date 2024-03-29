;assembly part using x86-64

section .data
prompt1 db "Enter scalar variable n: ", 0		;13 10 is the \n
prompt2 db "Enter values of vector A (single precision): ", 0
prompt3 db "Enter values of vector B (single precision): ", 0

n dq 0
var1 dq 0.0
var2 dq 0.0

scanInt db "%d",0
scanFloat db "%f",0

msg db "Da numbers are %d, %f, %f", 13,10,0

section .text
bits 64								;to tell 64 bits
default rel							;to support address relocation and relativity

									;above is standard part of template

global get_input				;so that c can regognize, equivalent of extern
extern printf, scanf

get_input:
	sub rsp, 8*5					;caller: if the assembly is caller we allocate stack pointer stack frame with 40 bytes
	lea rcx, [prompt1]				;Enter scalar variable n: 
	call printf

	lea rdx, [n]
	mov rcx, scanInt
	call scanf

	lea rcx, [prompt2]				;Enter values of vector A (single precision): 
	call printf

	lea rdx, [var1]
	mov rcx, scanFloat
	call scanf

	lea rcx, [prompt3]				;Enter values of vector B (single precision): 
	call printf
	
	lea rdx, [var2]
	mov rcx, scanFloat
	call scanf

							;DIS NEEDS TO BE EDITED PA, IT SOWS GARBAGE VALS LANG
	lea rcx, [msg]					;"Da numbers are %d, %f, %f", 13,10,0
	call printf

	add rsp, 8*5					;adjust back the pointer


	ret


	;takeaway: first 4 params free, rcx, rdx, r8, r9. if more create stack frame and adjust