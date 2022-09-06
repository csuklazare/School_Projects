; Author: Fritz Sieker
;
; ------------------------------------------------------------------------
; Begin reserved section - do not change ANYTHING is this section
; except the .FILL values of option, data1, data2

               .ORIG x3000
               BR Main

option         .FILL 0          ; select routine to test
data1          .FILL #20          ; use ONLY for testing
data2          .FILL #10          ; use ONLY for testing

stackBase      .FILL X4000      ; initial sttack pointer

Main           LD R6,stackBase  ; initialize stack pointer
               LD R0,option     ; select routine to test
               BRZ testPrintNum ; option = 0 means test printNum

               ADD R0,R0,#-1
               BRZ testGetDigit ; option = 1 means test getDidit

               ADD R0,R0,#-1
               BRZ testDivRem   ; option = 2 means test divRem

               HALT             ; invalid option if here

testPrintNum                    ; call printNum(x, base)
               LD R0,data2
               PUSH R0          ; push base argument
               LD R0,data1
               PUSH R0          ; push value argument
               JSR printNum
               ADD R6,R6,#2     ; caller clean up 2 parameters
               BR endTest

testGetDigit                    ; call getChar(val)
               LD R0,data1
               PUSH R0          ; push argument (val to convert to ASCII)
               JSR getDigit     ; 
               POP R0           ; get the corresponding character
               ADD R6,R6,#1     ; caller clean up 1 parameter
               OUT              ; print the digit
               NEWLN
               BR endTest

testDivRem                      ; call divRem(num, denom, *quotient, *remainder)
               LEA R0,data2     ; get pointer to remainder (&data2)
               PUSH R0
               LEA R0,data1     ; get pointer to quotient (&data1)
               PUSH R0
               LD R0,data2
               PUSH R0          ; push demoninator
               LD R0,data1
               PUSH R0          ; push numerator
               JSR divRem       ; call routine
               ADD R6,R6,#4     ; caller clean up 4 parameters

endTest        LEA R0,endMsg
               PUTS
theEnd         HALT             ; look at data1/data2 for quotient/remainder

                                ; useful constants
endMsg         .STRINGz "\nTest complete!\n"

negSign        .FILL    x2D     ; ASCII '-'
digits         .STRINGZ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ; up to base 36

; end reserved section

; ------------------------------------------------------------------------
; Author: your name goes here
; ------------------------------------------------------------------------
;
; C declaration: char getDigit (int val);

getDigit                        ; callee setup
		ADD R6, R6, #-1	; create space for return value
		PUSH R7		; push R7 for return address
                PUSH R5         ; push R5 for return frame pointer

		LEA R1, digits	; load address of the first digit and store it in R3
		LDR R0, R6, #3	; load R0 with initial value
		BRz SKIP1	; if positive, it will enter loop, else skip.
		Loop1		
			ADD R1, R1, #1	; increment the digit
			ADD R0, R0, #-1	; decrement R0
		BRp Loop1
		SKIP1
		
		LDR R1, R1, #0	; load return value into R3
		STR R1, R6, #2	; store return value into stack
		POP R5		; pop stack frame pointer into R5
                POP R7          ; pop return address into R7
               RET              ; return
; ------------------------------------------------------------------------
;
; C declaration: void divRem(int num, int denom, int*quotient, int*remainder);

divRem                          ; callee setup
		PUSH R7		; push return address
		PUSH R5 	; push frame pointer
		ADD R5, R6, #-1	; have R5 point to first local variable
		ADD R6, R6, #-1	; create space for local variable

		LDR R0, R6, #3	; load R0 with numerator	
		LDR R5, R6, #3	; load R5 with numerator as well
                LDR R1, R6, #4  ; load R1 with denominator
		LDR R2, R6, #4	; load R2 with denominator as well
                NOT R1, R1      ; flip bits of denominator
                ADD R1, R1, #1  ; add 1 for 2's complement
		AND R4, R4, #0	; initialize R4 to 0
		Loop2
			ADD R4, R4, #1	; increment R4 to keep track of quotient
			ADD R0, R0, R1	; subtract denom from numerator, store in R0
		BRp Loop2
		BRz SKIP2
			ADD R4, R4, #-1	; decrement R4 1 time since it counts 1 too many times, only if there is a remainder
		SKIP2
		LDR R1, R6, #5	; load R1 with address to quotient
		STR R4, R1, #0	; store quotient value at R1 location (data1)
		AND R1, R1, #0	; initialize R1 to 0
		Loop3
			ADD R1, R1, R2	; add R2 to itself R4 times, store in R1
			ADD R4, R4, #-1	; decrement R4
		BRp Loop3
		NOT R1, R1	; flip bits of R1
		ADD R1, R1, #1	; add 1 to R2 for 2's complement
		ADD R0, R1, R5	; add numerator with negative denominator*quotient
		BRzp SKIP3	; if number is negative, return numerator as remainder
			AND R0, R0, #0	; initialize R0 to 0
			ADD R0, R0, R5	; add numerator to R0
		SKIP3
		LDR R1, R6, #6	; load R1 with address to remainder
		STR R0, R1, #0	; store value of R0 at R1/remainder location

		ADD R6, R6, #1	; remove local variable from stack
		POP R5		; pop stack frame pointer into R5
		POP R7		; pop return address into R7
               RET              ; return
; ------------------------------------------------------------------------
;
; C declaration: void printNum (int val, int base);

printNum                        ; callee setup

		PUSH R7		; push R7 onto stack
		PUSH R5		; push R5 onto stack
		ADD R5, R6, #-1	; have R5 point to first local variable
		ADD R6, R6, #-2	; create 2 spaces for 2 local variables
		
		LDR R3, R6, #5	; initialize R4 to be the base value
		AND R0, R0, #0	; initialize R0 to 0
		ADD R0, R0, R5	; load R0 with address of R5
		STR R0, R5, #0	; store address into first local variable, will become the remainder
		ADD R5, R5, #-1	; increment R5 to point at second local variable
		AND R0, R0, #0	; initialize R0 to 0
		ADD R0, R0, R5	; load R0 with address of R5
		STR R0, R5, #0	; store address into second local variable, will become the quotient
		LDR R0, R6, #5	; push base onto stack
		PUSH R0
		LDR R0, R6, #5	; push value onto stack
		PUSH R0
		JSR divRem	; call divRem to determine quotient and remainder
		LDR R1, R5, #1	; load R1 with remainder
		LDR R0, R5, #0	; load R0 with quotient
		
		BRz Basecase	; detect base case (quotient = 0)

		;;; detect base case
		ADD R6, R6, #2	; decrement stack to to replace base and value #'s
		PUSH R3		; push original base value
		PUSH R0		; push quotient (new "value")
		JSR printNum	; recursively call printNum with new quotient
		LDR R0, R5, #1	; load R0 with remainder
		PUSH R0		; push R0 onto stack
		JSR getDigit	; print digit
		POP R0		; pop digit out
		ADD R6, R6, #1	; decrement stack
		OUT		; print digit

		BR Finish

Basecase	LDR R0, R5, #1	; if basecase, load register R0 with remainder value at R5
		PUSH R0		; push R0 onto stack
		JSR getDigit	; print digit
		POP R0		; pop digit out
		ADD R6, R6, #1	; decrement stack
		OUT
		;;;;;;; end of base case

Finish          ADD R6, R6, #4	; remove local variables from stack
		POP R5		; pop stack frame pointer into R5
		POP R7 		; pop return address into R7
               RET              ; return
; ------------------------------------------------------------------------
               .END
