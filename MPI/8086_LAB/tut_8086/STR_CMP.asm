DATA SEGMENT
 
STR1 DB "WWE","$"
STR2 DB "WWF","$"
MSG1 DB "EQUAL$"
MSG2 DB "NOT EQUAL$"
 
DATA ENDS
 

 

 
CODE SEGMENT
ASSUME CS:CODE,DS:DATA,ES:EXTRA
START: MOV AX,DATA
       MOV DS,AX
       
       LEA SI,STR1
       LEA DI,STR2
       
       MOV CX,20H
       
       REPE CMPSB
       JE A
       JNE B
       
       A:
       MOV DX,OFFSET MSG1
       MOV AH,09H
       INT 21H
       HLT
       JMP EXIT
       
       B:
       MOV DX,OFFSET MSG2
       MOV AH,09H
       INT 21H
       HLT
       JMP EXIT
       
       EXIT:HLT       

CODE ENDS
END START