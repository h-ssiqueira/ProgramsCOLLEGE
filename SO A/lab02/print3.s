global print3
section .text

print3:
	push rdx
	push rax
	mov rdx, rsi    ; rdx recebe o número de caracteres que serão impressos
    mov rsi, rdi    ; rsi recebe o endereço da string
	mov rax, 1      ; 1 = código syscall para write
	mov rdi, 1      ; 1 = escrita na tela (stdout)
    syscall
	pop rax
	pop rdx
    ret
