[ORG 7C00h]
[BITS 16]

mov ax, 0xb800
mov ds, ax
xor bx, bx

mov word[ds:bx], 'A0' ;Letra preta, fundo azul claro
add bx, 2
mov word[ds:bx], 'B1' ;Letra azul escuro, fundo azul claro
add bx, 2
mov word[ds:bx], 'C2' ;Letra verde, fundo azul claro
add bx, 2
mov word[ds:bx], 'D3' ;Letra azul claro, fundo azul claro
add bx, 2
mov word[ds:bx], 'E4' ;Letra vermelho, fundo azul claro
add bx, 2
mov word[ds:bx], 'F5' ;Letra rosa, fundo azul claro
add bx, 2
mov word[ds:bx], 'G6' ;Letra marrom, fundo azul claro
add bx, 2
mov word[ds:bx], 'H7' ;Letra cinza, fundo azul claro
add bx, 2
mov word[ds:bx], 'I8' ;Letra chumbo, fundo azul claro
add bx, 2
mov word[ds:bx], 'J9' ;Letra roxo, fundo azul claro
add bx, 2
mov word[ds:bx], 'K?'
add bx, 2
mov word[ds:bx], 'Lh'
add bx, 2
mov word[ds:bx], 'Ma'
add bx, 2
mov word[ds:bx], 'N]'
add bx, 2
mov word[ds:bx], 'O!'
add bx, 2
mov word[ds:bx], 'P '
add bx, 2
mov word[ds:bx], 'H+'
add bx, 2
mov word[ds:bx], 'Y{'
add bx, 2
mov word[ds:bx], 0000000101001000b

;cor de fundo(4b) / cor da letra(4b) / letra(8b)

;128 combinações 16 cores diferentes, sendo 16 para texto e 8 para fundo <https://www.hisour.com/bios-color-attributes-27184/>

loop_infinito:
	jmp loop_infinito

times 510 - ($-$$)	db 0
					dw 0AA55h
times 18 * 80 * 2 * 512 -($-$$)	db 0