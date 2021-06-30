[ORG 7C00h]
[BITS 16]

loop_infinito:
	jmp loop_infinito

times 510 - ($-$$) 	db 0
					db 0x55
					db 0xAA
times 18 * 80 * 2 * 512 -($-$$) db 0