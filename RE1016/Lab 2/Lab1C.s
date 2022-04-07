		AREA	ARMEX, 	CODE,	READONLY

		ENTRY
		mov 	r1, #10 
		mov 	r2, #5 
		subs 	r3, r2, r1 ; r3=r2-r1 (N flag)
		subs 	r4, r4, r4 ; r4=r4-r4 (Z and C flag)
		addeq 	r5, r1, r1 ; what is r5 equal to?
		addeq 	r6, r5, r1 ; what about r6?
		addeqs 	r7, r6, r1 ; and now r7!
		bge 	skip 
		sub 	r7, r6, r5 
skip 
		nop 
		mvns 	r1, #1 ; what about the N flag?
		movs 	r2, #1 
		add 	r3, r1, r2 
		orrs 	r1, r2 ; what does this code do?
		ldr 	r1, =0xFFFFFFFE ; note the C flag 
		adds 	r2, r1, #0x3 
		ldr 	r2, =0x7FFFFFFF ; note the V flag
		adds 	r3, r2, #0x4 
		
		END