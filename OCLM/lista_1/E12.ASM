TITLE EX12
.MODEL SMALL
.STACK 100H
.DATA
M1	DB	"DIVIDENDO: $"
M2  DB  10,13,"DIVISOR: $"
M3 	DB	10,13,"QUOCIENTE: $"
M4 	DB	10,13,"RESTO: $"
.CODE
MOV	AX, @DATA
MOV DS, AX

MOV	CL, 48

MOV AH,9
LEA	DX,M1
INT	21H

MOV	AH,1
INT	21H

MOV	BL,AL
CMP	BL,48
JE	FIM

MOV	AH,9
LEA DX,M2
INT 21H

MOV AH,1
INT 21H

MOV BH,AL
CMP BH,48
JE FIM

CMP BH,BL
JA FIM

SUB BH,48
SUB BL,48

INICIO:

SUB BL, BH
INC CL

CMP BH,BL
JB INICIO

ADD BL,48

FIM: 

MOV AH,9
LEA DX,M3
INT 21H

MOV AH,2
MOV DL, CL
INT 21H

MOV AH,9

LEA DX,M4
INT 21H

MOV AH,2
MOV DL,BL
INT 21H

MOV AH,4CH
INT 21H
END