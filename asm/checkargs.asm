SECTION .DATA
NO_ARGS: DB "no args.", 10
.LENGTH:	EQU	$ - NO_ARGS

SECTION .TEXT
GLOBAL _start

_start:		MOV	RCX,	QWORD [RSP]	;ARGC
		CMP	RCX,	2
		JL	EXIT.NO_ARGS

		XOR	RDI,	RDI

EXIT:		MOV	RAX,	60
		SYSCALL

.NO_ARGS:	MOV	RSI,	NO_ARGS
		MOV	RDX,	NO_ARGS.LENGTH
		CALL	PRINT

		MOV	RDI,	1
		JMP	EXIT

;RSI,	BUF
;RDI,	BUFSIZE
PRINT:		MOV	RAX,	1
		MOV	RDI,	1
		SYSCALL
		RET
