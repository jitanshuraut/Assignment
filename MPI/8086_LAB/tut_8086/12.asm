DATA SEGMENT
    DATA ENDS


CODE SEGMENT
    ASSUME CS:CODE ,DS:DATA
    
START:MOV AX,DATA
      MOV DS,AX
    MOV CX,[0500H] 
	MOV AX, 0001H	
	MOV DX, 0000H
ML:	MUL CX	
	LOOP ML
	MOV [0600H], AX	
	MOV [0601H], DX
	MOV DX,60H	
	             
	MOV AH,2H
	INT 21H             
	             
	HLT
	
	CODE ENDS

END START
	
     



