global _start
section .text
_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 35
    syscall
    
    mov rax, 60
    xor rdi, rdi
    syscall
    
section .data
    msg: db "Henrique Sartori Siqueira", 10, "19240472", 10
