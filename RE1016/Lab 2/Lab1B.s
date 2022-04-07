		AREA	ARMEX, 	CODE,	READONLY

		ENTRY
start	mov		r1,	#200
		mov		r1,	#0x00002000
		mov		r2,	#0x3c
loop	str		r2,	[r1]
		add		r2,	r2,	#1
		b		loop
		
		b		start
		
		END