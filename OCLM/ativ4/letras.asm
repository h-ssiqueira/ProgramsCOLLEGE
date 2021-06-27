TITLE Letras
.MODEL SMALL
.STACK 100h
.CODE
; Inicializa o contador (CX) com o valor 26 (quantidade de letras)
MOV CX,26
; Inicializa o registrador BL com o código ASCII da letra “A” (código ASCII: 65)
MOV BL,65
; Define um rótulo chamado INICIO
INICIO:
; Exibe na tela a letra armazenada em BL
MOV AH,2
MOV DL, BL
INT 21h
; Incrementa o valor de BL (muda para a próxima letra)
INC BL
; Decrementa o contador (CX) e:
; caso o contador (CX) seja diferente de zero: salta para INICIO
; caso o contador (CX) seja igual a zero: continua a execução sequencialmente
LOOP INICIO
; Finaliza o programa
MOV AH,4Ch
INT 21h
END