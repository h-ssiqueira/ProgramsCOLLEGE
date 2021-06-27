TITLE Numero
.MODEL SMALL
.STACK 100h
.DATA
MSG1 DB "Digite um caracter: $"
SIM DB 10,13,"O caracter digitado e um numero.$"
NAO DB 10,13,"O caracter digitado nao e um numero.$"
.CODE
; Permite o acesso às variáveis definidas em .DATA
MOV AX,@DATA
MOV DS,AX
; Exibe na tela a string MSG1 (“Digite um caracter: ”)
MOV AH,9
LEA DX,MSG1
INT 21h
; Lê um caracter do teclado e salva o caracter lido em AL
MOV AH,1
INT 21h
; Copia o caracter lido para BL
MOV BL,AL
; Compara o caracter em BL com o valor 48 (código ASCII do caracter “0”)
CMP BL,48
; Se o caracter em BL for menor que 48 (“0”), salta para o rótulo NAOENUMERO
JB NAOENUMERO
; Compara o caracter em BL com o valor 57 (código ASCII do caracter “9”)
CMP BL,57
; Se o caracter em BL for maior que 57 (“9”), salta para o rótulo NAOENUMERO
JA NAOENUMERO
; Se chegou até aqui, exibe na tela dizendo que o caracter é um número
MOV AH,9
LEA DX,SIM
INT 21h
; Salta para o rótulo FIM
JMP FIM
; Define o rótulo NAOENUMERO
NAOENUMERO:
; Exibe na tela dizendo que o caracter não é um número
MOV AH,9
LEA DX,NAO
INT 21h
; Define o rótulo FIM
FIM:
; Finaliza o programa
MOV AH,4Ch
INT 21h
END