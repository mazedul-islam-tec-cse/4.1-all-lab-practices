;*****************************************
;     MDA-Win8086 EXPERIMENT PROGRAM    *
;     FILENAME  : INT1.ASM
;     PROCESSOR : I8086
;*****************************************
CODE	SEGMENT
	ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE
	;
	ORG	1000H
	MOV	AX,1234H
	MOV	BL,00H
	DIV	BL
	NOP
	NOP
	INT	3
	;		
CODE	ENDS
	END


