; Blink_LED.s   Lab #2 sample program
; This program blink the LEDs on the DE0 board

; Stack related directives
	AREA    STACK, NOINIT, READWRITE, ALIGN=4	; Name this block of code as STACK, reside in the RAM area
Stack_Size  EQU     0x200						; Stack Size = 0x200 bytes
Stack_Mem   SPACE   Stack_Size				    ; Reserve the space in RAM
TOP_STACK										; Set top of stack location

; Vector Table - link to Address 0 at Reset
	AREA    RESET, DATA, READONLY				; Name this block of code as RESET, reside in the ROM area
__Vectors   DCD     TOP_STACK           		; Vector table start here, first enty is the 'Top of stack'
			DCD		START						; second entry is the Reset vector address

; User Application
	AREA    texts, CODE, READONLY     			; Name this block of code as texts, reside in the ROM area
ENTRY                       					; Mark first instruction to execute
START   	PROC								; Declaration of subroutine/function 
			LDR		R2,=0xA0000000				; Store address 0xA0000000 in R2
leds_even	LDR		R0,=0x2AA					; Store address 0x2AA in R0, even LEDS
			STR     R0,[R2,#0x00]        		; Store the value to the DE0_LED address
			BL    	DELAY                    	; Call the DELAY function
leds_odd	LDR    	r0,=0x155            		; MOVE new value of 0x155 to r0, odd LEDS
			STR     r0,[r2,#0x00]      			; Store the value to the DE0_LED address
			BL    	DELAY                   	; Call the DELAY function
			B    	leds_even                 	; Repeat
			ENDP                            	; END of this subroutine

;Delay subroutine
COUNTER 	EQU     0xFFFFF                		; Counter to be used for delay looping

DELAY		PROC                        		; Declaration of DELAY subroutine
			MOVS	R4,#3
delay0    	ldr 	R3,=COUNTER            		; Initialize R3 with delay COUNTER
delay1    	SUBS 	R3,#1           
			BNE 	delay1
			SUBS 	R4,#1
			BNE 	delay0
			BX 		LR                     		;Return to the calling function
			ENDP   
	


; The following codes are not used in this application, but their symbols are required for error-free linking by default linker setup	
	            EXPORT  __Vectors				; default symbol required by the linker, not used in this program      
				EXPORT  Reset_Handler           ; default symbol required by linker, not needed in this program
				
	AREA    texts, CODE, READONLY, ALIGN=4
Reset_Handler   PROC							; Typical code for Reset_vector handler
                LDR     R0, =START				; User Application called by Label
                BX      R0
                ENDP
	
			END   									; End of code. Assembler ignore code beyind this point    