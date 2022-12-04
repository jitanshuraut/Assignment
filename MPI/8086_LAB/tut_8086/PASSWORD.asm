DATA_HERE SEGMENT
    MSG DB "ENTER YOUR PASSWORD",0AH,0DH,"$"
    INVAILD DB "INVALID PASSWORD",0AH,0DH,"$"
    VAILD DB "VALID PASSWORD",0AH,0DH,"$" 
    PASSWORD DB "PASSWORD",0AH,0DH,"$"
    
    DATA_HERE ENDS   


EXTRA_HERE SEGMENT
    deststr DB 20 DUP(11)
    EXTRA_HERE ENDS

CODE_HERE SEGMENT
    ASSUME CS:CODE_HERE, DS:DATA_HERE
START: MOV AX, DATA_HERE
       MOV DS, AX
     
       LEA DX,MSG
       MOV AH,09H
       INT 21H
                               
                               
       MOV BX,OFFSET PASSWORD  
       MOV CX,8H
       
   L:MOV AH,01H
     INT 21H
     
     CMP AL,[BX]
     JNE E
     INC BX
     LOOP L  
     
     LEA DX,VAILD
     MOV AH,09H
     JMP EXIT 
     
     
     
     
    E:LEA DX,INVAILD
      MOV AH,09H
      INT 21H
      
   EXIT:
        HLT    
     
       
       CODE_HERE ENDS
END START




