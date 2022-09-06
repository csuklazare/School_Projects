; Begin reserved section: do not change ANYTHING in reserved section!
; The ONLY exception to this is that you MAY change the .FILL values for
; Option, Value1 and Value2. This makes it easy to initialize the values in the
; program, so that you do not need to continually re-enter them. This
; makes debugging easier as you need only change your code and re-assemble.
; Your test value(s) will already be set.
;------------------------------------------------------------------------------
; Author: Fritz Sieker
;
; Description: Tests the implementation of a simple string library and I/O
;

            .ORIG x3000
            BR Main
Functions
            .FILL Test_pack         ; (option 0)
            .FILL Test_unpack       ; (option 1)
            .FILL Test_printCC      ; (option 2)
            .FILL Test_strlen       ; (option 3)
            .FILL Test_strcpy       ; (option 4)
            .FILL Test_strcat       ; (option 5)
            .FILL Test_strcmp       ; (option 6)

; Parameters and return values for all functions
Option      .FILL 0                 ; which function to call
String1     .FILL x4000             ; default location of 1st string
String2     .FILL x4100             ; default location of 2nd string
Result      .BLKW 1                 ; space to store result
Value1      .FILL 0                 ; used for testing pack/unpack
Value2      .FILL 0                 ; used for testing pack/unpack
lowerMask   .FILL 0x00FF            ; mask for lower 8 bits
upperMask   .FILL 0xFF00            ; mask for upper 8 bits

Main        LEA R0,Functions        ; get base of jump table
            LD  R1,Option           ; get option to use, no error checking
            ADD R0,R0,R1            ; add index of array
            LDR R0,R0,#0            ; get address to test
            JMP R0                  ; execute test

Test_pack   
            LD R0,Value1            ; load first character
            LD R1,Value2            ; load second character
            JSR pack                ; pack characters
            ST R0,Result            ; save packed result
End_pack    HALT                    ; done - examine Result

Test_unpack 
            LD R0,Value1            ; value to unpack
            JSR unpack              ; test unpack
            ST R0,Value1            ; save upper 8 bits
            ST R1,Value2            ; save lower 8 bits
End_unpack  HALT                    ; done - examine Value1 and Value2

Test_printCC    
            LD R0,Value1            ; get the test value
            .ZERO R1                ; reset condition codes
            JSR printCC             ; print condition code
End_printCC HALT                    ; done - examine output

Test_strlen 
            LD R0,String1           ; load string pointer
            GETS                    ; get string
            LD R0,String1           ; load string pointer
            JSR strlen              ; calculate length
            ST R0,Result            ; save result
End_strlen  HALT                    ; done - examine memory[Result]

Test_strcpy 
            LD R0,String1           ; load string pointer
            GETS                    ; get string
            LD R0,String2           ; R0 is dest
            LD R1,String1           ; R1 is src
            JSR strcpy              ; copy string
            PUTS                    ; print result of strcpy
            NEWLN                   ; add newline
End_strcpy  HALT                    ; done - examine output

Test_strcat 
            LD R0,String1           ; load first pointer
            GETS                    ; get first string
            LD R0,String2           ; load second pointer
            GETS                    ; get second string
            LD R0,String1           ; dest is first string
            LD R1,String2           ; src is second string
            JSR strcat              ; concatenate string
            PUTS                    ; print result of strcat
            NEWLN                   ; add newline
End_strcat  HALT                    ; done - examine output

Test_strcmp 
            LD R0,String1           ; load first pointer
            GETS                    ; get first string
            LD R0,String2           ; load second pointer
            GETS                    ; get second string
            LD R0,String1           ; dest is first string
            LD R1,String2           ; src is second string
            JSR strcmp              ; compare strings
            JSR printCC             ; print result of strcmp
End_strcmp  HALT                    ; done - examine output

;------------------------------------------------------------------------------
; End of reserved section
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; on entry R0 contains first value, R1 contains second value
; on exit  R0 = (R0 << 8) | (R1 & 0xFF)

pack        ; fill in your code, ~11 lines of code
returnadd1	ST R7, returnadd1		
		LD R2, lowermask	; load lowermask
		AND R0, R0, R2		; use mask to isolate lower bits
		AND R1, R1, R2		; use mask to isolate lower bits
		AND R4, R4, #0		; initialize R4 to 0
		ADD R4, R4, #8		; initiate counter
		Loop1
			ADD R0, R0, R0	; add R1 to itself to move bits to the left
			ADD R4, R4, #-1	; decrement counter
		BRp Loop1		; end of loop
		ADD R0, R0, R1		; add result of R1 to R0
		LD R7, returnadd1
            RET

;------------------------------------------------------------------------------
; on entry R0 contains a value
; on exit  (see instructions)

unpack      ; fill in your code, ~14 lines of code
returnadd	ST R7, returnadd	; save returnaddress for later
		LD R2, uppermask	; load upppermask
		LD R3, lowermask	; load lowermask 
r1value		AND R1, R0, R3		; isolate lower bits and store in R1. R1 is complete
		ST R1, r1value
		AND R0, R0, R2		; isolate upper bits and store in R0
		AND R3, R3, #1		; set r3 to 0
		AND R4, R4, #0		; initialize R4 to 0
		ADD R4, R4, #8		; set counter to 8
		Loop3
			ADD R3, R3, R3	; add r3 to itself
			ADD R4, R4, #-1	; decrement counter 
		BRp Loop3
		AND R2, R2, #0		; set r2 to 0
		ADD R2, R2, #1		; initialize destmask		
		ADD R4, R4, #9		; initiate counter
		AND R1, R1, #0		; set R1 to 0
		AND R7, R7, #0		; set R7 to 0
		Loop2
			AND R7, R3, R0	; check if digit in R0 equals 1
			BRz SKIP1	; if statement
				ADD R1, R1, R2	; add bit to result
			SKIP1
			ADD R2, R2, R2	; increment destmask
			ADD R3, R3, R3	; increment sourcemask
			ADD R4, R4, #-1	; decrement counter
		BRp Loop2		; end of loop
		ADD R0, R1, #0		; final answer stored in R0
		LD R1, r1value		; load value of r1value into r1
		LD R7, returnadd	; set proper return address
            RET

;------------------------------------------------------------------------------
; on entry R0 contains value
; on exit  (see instructions)

StringNEG   .STRINGZ "NEGATIVE\n"   ; output strings
StringZERO  .STRINGZ "ZERO\n"
StringPOS   .STRINGZ "POSITIVE\n"

printCC     ; fill in your code, ~11 lines of code
returnadd2      ST R7, returnadd2
origR0		ST R0, origR0
		ADD R1, R1, R0	; set CC code
		BRnz SKIP2
			LEA R0, StringPOS
			PUTS
		SKIP2
		BRzp SKIP3
			LEA R0, StringNEG
			PUTS
		SKIP3
		BRnp SKIP4
			LEA R0, StringZERO
			PUTS
		SKIP4
		LD R0, origR0
		LD R7, returnadd2
            RET

;------------------------------------------------------------------------------
; size_t strlen(char *s)
; on entry R0 points to string
; on exit  (see instructions)

strlen				        ; fill in your code, ~7 lines of code
returnadd3	ST R7, returnadd3	; save return address
length		AND R3, R3, #0 		; set R3 to 0
		LDR R4, R0, #0
		BRz SKIP8
		Loop4
			ADD R3, R3, #1	; increment length
			ADD R0, R0, #1	; decrement word
			LDR R4, R0, #0   ; check to see if the word is done. Since R0 = 0 at end of word, if word has a letter left, it will show negative.
		BRnp Loop4
		SKIP8
		ST R3, length		; store result in length
		LD R0, length		; load length in R0	 
		LD R7, returnadd3	; load correct return address
            RET

;------------------------------------------------------------------------------
; char *strcpy(char *dest, char *src)
; on entry R0 points to destination string, R1 points to source string
; on exit  (see instructions)

returnadd4   .BLKW 1			; space for return address
deststring   .BLKW 1			; space for destination string

strcpy     			        ; fill in your code, ~8 lines of code
		ST R7, returnadd4	; store return address
		ST R0, deststring	; save destination string pointer
		Loop5
			LDR R7, R1, #0 	; load character into R7
			STR R7, R0, #0	; store value of R1 at address R0
		        ADD R0, R0, #1  ; increment destination string
			ADD R1, R1, #1	; increment source string
			LDR R4, R1, #0	; check to see if the whole word has been copied.
		BRp Loop5
		ADD R0, R0, #1		; add null terminator
		LD R0, deststring	; load R0 with pointer to beginning of destination string		
		LD R7, returnadd4	; load correct return address
            RET

;------------------------------------------------------------------------------
; char *strcat(char *dest, char *src)
; on entry R0 points to destination string, R1 points to source string
; on exit  (see instructions)

strcat_RA   .BLKW 1                 ; space for return address
strcat_dest .BLKW 1                 ; space for dest
strcat_src  .BLKW 1                 ; space for src

strcat      ST R7,strcat_RA         ; save return address
            ST R0,strcat_dest       ; save dest
            ST R1,strcat_src        ; save src

            ; fill in your code, ~5 lines of code
            ; HINT: call strlen and strcpy
		ADD R0, R0, #0		; set proper CC
offset		JSR strlen		; call strlen to get length of string in R0
		ST R0, offset		; store length in offset variable
		LD R2, strcat_dest	; load destination string into R2
		ADD R2, R2, R0		; Add offset to R2 to get correct location of concat string
		ADD R0, R2, #0		; copy R2 to R0
		JSR strcpy		; copy string to back end of destination string

            LD R0,strcat_dest       ; restore dest
            LD R7,strcat_RA         ; restore return address
            RET

;------------------------------------------------------------------------------
; int strcmp(char *s1, char *s2)
; on entry R0 points to first string, R1 points to second string
; on exit  (see instructions)

strcmp      ; fill in your code, ~12 lines of code
returnadd5	ST R7, returnadd5	; store correct return address
compare		AND R3, R3, #0		; set R3 to 0
		Loop6
			AND R3, R0, R1	; compare 1st character, store in R3
			BRnp SKIP5
				ST R3, compare	; store R3 in compare
			BRnzp Loop6	; end loop
			SKIP5		
			ADD R1, R1, #1	; increment
			ADD R0, R0, #1	; increment
		BRzp Loop6
		ST R3, compare		; if n or p is not triggered, store z in compare
		LD R0, compare		; load compare into R0
		LD R7, returnadd5	; load correct return address
            RET

;------------------------------------------------------------------------------
            .END
