ASSUME CS: CODE, DS: DATA, ES: EXTRA DATA SEGMENT
OPR1 DW 5169H OPR2 DW 1000H
DATA ENDS
EXTRA SEGMENT
SUM DW ?
EXTRA ENDS CODE SEGMENT
START: MOV AX, DATA
MOV DS, AX ; REGISTER ADDRESING MODE MOV AX, OPR1 ; DIRECT ADDRESSING MODE ADD AX, OPR2 ; DIRECT ADDRESSING MODE MOV SUM, AX ; DIRECT ADDRESSING MODE INT 03H
CODE ENDS END START END