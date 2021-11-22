;*****************************************
;     MDA-Win8086 EXPERIMENT PROGRAM    *
;     FILENAME  : LOOP.ASM
;     PROCESSOR : I8086
;*****************************************
	CODE	SEGMENT
	ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE
	ORG	1000H
	MOV	AX,0000H
	MOV	DS,AX
	;
	MOV	SI,20FFH
	MOV	BL,10H
L1:	MOV	CX,0010H
L2:	MOV	[SI],BL
	DEC	SI
	LOOP	L2
	DEC	BL
	JNZ	L1
	;
	INT	3
	;
CODE	ENDS
	END


