TITLE EX8
.MODEL SMALL
.STACK 100h
.DATA
	M1 	DB 10,13,"DIGITE ALGO:$"
.CODE
MOV AX,@DATA
MOV DS,AX

INP:
MOV AX,@DATA
MOV DS,AX

MOV AH,9
LEA DX,M1
INT 21h

MOV AH,1
INT 21h

MOV BL,AL

CMP BL,32
JE FIM
JNE INP

FIM:
MOV AH,4Ch
INT 21h

END