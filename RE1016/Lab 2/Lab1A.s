		AREA	ARMEX, 	CODE,	READONLY

		ENTRY
start	mov 	r0,	#200
loop	subs	r0,	r0,	#3
		bge		loop
		mov 	r1, r0
		
		END