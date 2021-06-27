TITLE Converte
.MODEL SMALL
.STACK 100h
.DATA
MSG1 DB "Digite uma letra minuscula: $"
MSG2 DB 10,13,"Convertida para maiuscula: $"
.CODE
; Permite o acesso às variáveis definidas em .DATA
MOV AX,@DATA
MOV DS,AX
; Exibe na tela a string MSG1 (“Digite uma letra minuscula: ”)
MOV AH,9
LEA DX,MSG1
INT 21h
; Lê um caracter do teclado e salva o caracter lido em AL
MOV AH,1
INT 21h
; Copia o caracter lido para BL
MOV BL,AL
; Exibe na tela a string MSG2 (“Convertida para maiuscula: ”)
MOV AH,9
LEA DX,MSG2
INT 21h
; Converte a letra minuscula para maiuscula (subtrai 32 de BL)
SUB BL,32
; Exibe a letra convertida (salva em BL)
MOV AH,2
MOV DL,BL
INT 21h
; Finaliza o programa
MOV AH,4Ch
INT 21h
END