TITLE E1
.MODEL SMALL
.STACK 100h
.DATA
    MSG DB "INSIRA UM NUMERO$"
    PAR DB 10,13,"EH PAR$"
    IMPAR DB 10,13,"EH IMPAR$"
.CODE
    MOV AX,@DATA
    MOV DS,AX

    MOV AH,9
    LEA DX,MSG
    INT 21h

    MOV AH,1
    INT 21h

    MOV BL,AL
    AND BL,00000001b
    JNZ IMPA

    MOV AH,9
    LEA DX,PAR
    INT 21h
    JMP FIM

IMPA:
    MOV AH,9
    LEA DX,IMPAR
    INT 21H

FIM:
    MOV AH,4Ch
    INT 21h
END