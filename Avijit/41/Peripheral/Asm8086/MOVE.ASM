;*****************************************
;     MDA-Win8086 EXPERIMENT PROGRAM    *
;     FILENAME  : MOVE.ASM
;     PROCESSOR : I8086
;*****************************************
CODE	SEGMENT
	ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE
	;
	ORG	1000H
	MOV	AX,1234H
	MOV	BX,5678H
	MOV	CX,1000H
	MOV	DX,2000H
	;
	MOV	DS,DX
	MOV	ES,AX
	;
	MOV	SI,AX
	MOV	DI,BX
	MOV	BP,3000H
	;
	INT	3
	;
CODE	ENDS
	END



