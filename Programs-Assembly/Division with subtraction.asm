;Escreva um PROCEDIMENTO que exibe o valor decimal armazenado no registrador Bx.
;Considere que o valor de Bx e um valor nao sinalizado (entre 0 e 65535).
;Dica: Bx=17458 ...

TITLE DESAFIO
.MODEL SMALL
.STACK 100H
.DATA
	CONTADOR DB ?
	MSG DB "Valor decimal armazenado no registrador Bx: $"
.CODE

SUBTRACAO PROC

DIVISAO:
	MOV CONTADOR,0
	JMP PRIMEIRA

MAIS: 
	MOV BX,CX
	MOV CX,0

PRIMEIRA:
	CMP BX,10 ;Bx resto
	JB CONTINUA

	SUB BX,10 ;Bx= 17458	Ax=10 

	INC CX ;CX Quociente

	JMP PRIMEIRA

CONTINUA:
	PUSH BX

	INC CONTADOR

	CMP CX,0
	JNE MAIS

	MOV AH,9
	LEA DX,MSG
	INT 21H

EXIBIR:
	MOV AH,2
	POP DX 
	ADD DL,48
	INT 21H

	DEC CONTADOR
	JNZ EXIBIR

	RET
SUBTRACAO ENDP


MAIN PROC
	MOV AX,@DATA
	MOV DS,AX

	MOV BX,17458
	;MOV AX,10
	MOV CX,0

	CALL SUBTRACAO


	MOV AH,4CH
	INT 21H

MAIN ENDP

END MAIN 