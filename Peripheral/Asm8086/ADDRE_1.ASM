;*****************************************
;     MDA-Win8086 EXPERIMENT PROGRAM    *
;     FILENAME  : ADDRE_1.ASM
;     PROCESSOR : I8086
;*****************************************
CODE	SEGMENT
	ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE
	;
        MOV     AX,0000H
        MOV     DS,AX
        MOV     SS,AX
        MOV     ES,AX
        ;
        MOV     BX,2000H
        MOV     BP,BX
        MOV     SI,2
        MOV     DI,4
        ;
        MOV     CL,[BX+SI+1]
        MOV     CH,[BP+DI+2]
        ;
        MOV     DX,[BP+SI+4]
        ;
        MOV     AL,[BX+SI]
        MOV     AH,[BP+SI]
        ;
        XCHG    AX,DX
        ;
        LEA     AX,[BX+SI+4]
        ;
        LES     BX,[BX+00]
        LDS     DI,[BX+SI]
        INT     3
	;
CODE	ENDS
	END
	
		
