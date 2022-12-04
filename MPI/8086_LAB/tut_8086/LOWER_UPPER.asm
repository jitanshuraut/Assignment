DATA SEGMENT
    
MSG1 DB 'ENTER A LOWER CASE LETTER $'
MSG2 DB 0DH,0AH, 'IN UPPER CASE ITS IS: '
CHAR DB 5 DUP(?),'$'
 
DATA ENDS
 

 
EXTRA SEGMENT
 
BLOCK2 DB 9 DUP(?)
EXTRA ENDS
 
CODE SEGMENT
ASSUME CS:CODE,DS:DATA,ES:EXTRA
START: 
 MOV AX, @DATA       ;get data segment
    MOV DS,AX           ;initailize DS
    
    ;print user prompt
    LEA DX,MSG1         ;get first message
    MOV AH,9            ;display sting function
    INT 21H            ;display first message 
   
    ;input a char and cover to upper case
    MOV AH,1H            ;read character function
    INT 21H             ;read a small letter into AL
    SUB AL, 20H         ;convert it to upper case
    MOV CHAR, AL        ;and store it
    
    ;display on the next line
    LEA DX,MSG2         ;get second message
    MOV AH,9            ;display message and uppercase
    INT 21H             ;letter in front
    
    ;DOS EXIT
    MOV AH,4CH
    INT 21H 
CODE ENDS
END START