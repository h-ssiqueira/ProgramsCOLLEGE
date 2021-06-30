[ORG 7C00h]
[BITS 16]

mov ax, 0xb800
mov ds, ax
xor bx, bx

mov word[ds:bx], 'A0'
add bx, 2
mov word[ds:bx], 'B1'

loop_infinito:
	jmp loop_infinito

times 510 - ($-$$)	db 0
					dw 0AA55h
times 18 * 80 * 2 * 512 -($-$$)	db 0