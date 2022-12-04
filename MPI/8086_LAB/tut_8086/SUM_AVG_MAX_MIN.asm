DATA_THERE SEGMENT 
    BCD DW 0005H;
    DATA_THERE ENDS

CODE_THAT SEGMENT
    ASSUME DS:DATA_THERE,CS:CODE_THAT
START:MOV AX,DATA_THERE
    MOV DS,AX 
    MOV BX,7500H
    MOV CL,10;
    MOV AX,0000H;
    MOV [BX],05H;
    MOV DH,[BX]
    MOV DL,[BX]
AGAIN:
ADD AL,DS:[BX]
    CMP DH,[BX]
    JNC MAX
    MOV DH,[BX]
 MAX:CMP DL,[BX]
    JC MIN
    MOV DL,[BX]
MIN:INC BX
    LOOP AGAIN
    MOV [BX],AL
    INC BX
    MOV CL,10;
    DIV CL;
    MOV [BX],AX
    INC BX
    INC BX
    MOV [BX],DX
    HLT
MOV AH,4CH;
INT 24H
CODE_THAT ENDS
END START
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   