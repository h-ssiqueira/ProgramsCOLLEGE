[ORG 7C00h]
[BITS 16]

mov ax, 0xb800
mov ds, ax
xor bx, bx

mov word[ds:bx], 0000010001001000b ;H
add bx, 2
mov word[ds:bx], 0000010001100101b ;e
add bx, 2
mov word[ds:bx], 0000010001101110b ;n
add bx, 2
mov word[ds:bx], 0000010001110010b ;r
add bx, 2
mov word[ds:bx], 0000010001101001b ;i
add bx, 2
mov word[ds:bx], 0000010001110001b ;q
add bx, 2
mov word[ds:bx], 0000010001110101b ;u
add bx, 2
mov word[ds:bx], 0000010001100101b ;e
add bx, 2
mov word[ds:bx], 0000010000100000b ;
add bx, 2
mov word[ds:bx], 0000010001010011b ;S
add bx, 2
mov word[ds:bx], 0000010001100001b ;a
add bx, 2
mov word[ds:bx], 0000010001110010b ;r
add bx, 2
mov word[ds:bx], 0000010001110100b ;t
add bx, 2
mov word[ds:bx], 0000010001101111b ;o
add bx, 2
mov word[ds:bx], 0000010001110010b ;r
add bx, 2
mov word[ds:bx], 0000010001101001b ;i
add bx, 2
mov word[ds:bx], 0000010000100000b ;
add bx, 2
mov word[ds:bx], 0000010001010011b ;S
add bx, 2
mov word[ds:bx], 0000010001101001b ;i
add bx, 2
mov word[ds:bx], 0000010001110001b ;q
add bx, 2
mov word[ds:bx], 0000010001110101b ;u
add bx, 2
mov word[ds:bx], 0000010001100101b ;e
add bx, 2
mov word[ds:bx], 0000010001101001b ;i
add bx, 2
mov word[ds:bx], 0000010001110010b ;r
add bx, 2
mov word[ds:bx], 0000010001100001b ;a
add bx, 2
mov word[ds:bx], 0000010000100000b ;
add bx, 2
mov word[ds:bx], 0000010000110001b ;1
add bx, 2
mov word[ds:bx], 0000010000111001b ;9
add bx, 2
mov word[ds:bx], 0000010000110010b ;2
add bx, 2
mov word[ds:bx], 0000010000110100b ;4
add bx, 2
mov word[ds:bx], 0000010000110000b ;0
add bx, 2
mov word[ds:bx], 0000010000110100b ;4
add bx, 2
mov word[ds:bx], 0000010000110111b ;7
add bx, 2
mov word[ds:bx], 0000010000110010b ;2

;00000100 fundo preto, letra vermelha
;cor de fundo(4b) / cor da letra(4b) / letra(8b)

loop_infinito:
	jmp loop_infinito

times 510 - ($-$$)	db 0
					dw 0AA55h
times 18 * 80 * 2 * 512 -($-$$)	db 0