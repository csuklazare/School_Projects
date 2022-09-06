; P5 Assignment
; Author: <Brock Fisher>
; Date:   <6/9/21>
; Email:  <Brock.Fisher@colostate.edu>
; Class:  CS270
;
; Description: Implements the arithmetic, bitwise, and shift operations

;------------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000
                BR Main

Functions       .FILL IntAdd         ; Address of IntAdd routine     (option 0)
                .FILL IntSub         ; Address of IntSub routine     (option 1)
                .FILL IntMul         ; Address of IntMul routine     (option 2)
                .FILL BinaryOr       ; Address of BinaryOr routine   (option 3)
                .FILL LeftShift      ; Address of LeftShift routine  (option 4)
                .FILL RightShift     ; Address of RightShift routine (option 5)

Main            LEA R0,Functions     ; The main routine calls one of the 
                LD  R1,Option        ; subroutines below based on the value of
                ADD R0,R0,R1         ; the Option parameter.
                LDR R0,R0,0          ;
                JSRR R0              ;
EndProg         HALT                 ;

; Parameters and return values for all functions
; Try changing the .BLKW 1 to .FILL xNNNN where N is a hexadecimal value or #NNNN
; where N is a decimal value, this can save you time by not having to set these 
; values in the simulator every time you run your code. This is the only change 
; you should make to this section.
Option          .FILL #0             ; Which function to call
Param1          .BLKW 1              ; Space to specify first parameter
Param2          .BLKW 1              ; Space to specify second parameter
Result          .BLKW 1              ; Space to store result

; End reserved section: do not change ANYTHING in reserved section!
;------------------------------------------------------------------------------

; You may add variables and functions after here as you see fit.

;------------------------------------------------------------------------------
IntAdd                               ; Result is Param1 + Param2
                                     ; Your code goes here (~4 lines)
		LD R1, Param1	     ; load parameter 1 in register 1
		LD R2, Param2	     ; load parameter 2 in register 2
		ADD R3, R1, R2	     ; Add registers together
		ST R3, Result	     ; Store answer in result
                RET
;------------------------------------------------------------------------------
IntSub                               ; Result is Param1 - Param2
                                     ; Your code goes here (~6 lines)
		LD R1, Param1        ; load param1 into register 1
                LD R2, Param2        ; load param2 into register 2
                NOT R2, R2           ; flip the bits for 2's complement
                ADD R2, R2, #1       ; add 1 to get 2's complement
                ADD R3, R2, R1       ; add negative to positive
                ST R3, Result        ; store answer in result

                RET
;------------------------------------------------------------------------------
IntMul                               ; Result is Param1 * Param2
                                     ; Your code goes here (~9 lines)
		ADD R3, R3, #0	     ; initialize register 3 to 0.
		LD R1, Param1	     ; load param1 into register 1
		LD R2, Param2	     ; load param2 into register 2
		BRz SKIP	     ; if param2 is 0, skip to end
Counter		ADD R4, R4, R2	     ; counter
		Loop1		     ; loop to multiply
			ADD R3, R3, R1	; add register 1 to register 3
			ADD R4, R4, #-1	; decrement counter, to add R1 to R3 R2 times
		BRp Loop1	     ; end of loop
		SKIP		     ; end of skip
		ST R3, Result	     ; store answer in result
                RET
;------------------------------------------------------------------------------
BinaryOr                             ; Result is Param1 | Param2
                                     ; Your code goes here (~7 lines)
		LD R1, Param1        ; load param1 into register 1
		LD R2, Param2	     ; load param2 into register 2
		NOT R1, R1	     ; not register 1 and store in register 1
		NOT R2, R2	     ; not register 2 and store in register 2
		AND R3, R1, R2	     ; and registers together
		NOT R3, R3	     ; flip bits
		ST R3, Result	     ; Store answer in result
                RET
;------------------------------------------------------------------------------
LeftShift                            ; Result is Param1 << Param2
                                     ; (Fill vacant positions with 0's)
                                     ; Your code goes here (~7 lines)
		LD R1, Param1	     ; load param1 into R1
		LD R2, Param2	     ; load param2 into R2
		LD R4, Param2	     ; load counter into R4 (param2)
		Loop2		     ; loop to shift
			ADD R1, R1, R1	; shift bits to left 1 bit
			ADD R4, R4, #-1	; decrement counter
		BRp Loop2	     ; end loop
		ST R1, Result	     ; store answer in result
                RET
;------------------------------------------------------------------------------
RightShift                           ; Result is Param1 >> Param2
                                     ; (Fill vacant positions with 0's)
                                     ; Your code goes here (~16 lines)
MaskOne		.FILL x0001	     ; initialize mask1. For some reason, my code will compile but it is saying I have an illegal instruction once it gets to this mask line. I don't know how to fix that or why it is giving me that as I followed the exact same formatting as on the last programming assingment when the Mask was declared as x00ff. I am out of time to try and fix this as well. I will be asking a question to the TA's regarding this as I believe my code would have worked otherwise on this part.
MaskTwo		.FILL x0000	     ; initialize mask2
		LD R1, Param1	     ; load param1 into register 1
		LD R2, Param2	     ; load param2 into register 2
		ADD R0, R2, #0	     ; copy R2 into R0 for counter
		LD R3, MaskOne	     ; initialize R3 to mask1
		LD R2, MaskTwo	     ; initialize R2 to mask2
		Loop4
			ADD R4, R3, R2		; create mask of 1's
			ADD R3, R3, R3 		; increment mask to next bit
			ADD R0, R0, #-1		; decrement counter
		BRp Loop4 	     ; end loop
SourceMask	NOT R4, R4	     ; created source mask to negate shifted bits
		LD R0, MaskTwo	     ; initialize result register to 0
		LD R3, MaskOne	     ; initialize destination mask
		LD R2, Param2	     ; reinitialize R2 to param2
		LD R2, MaskTwo	     ; clear register 2
Counter2	ADD R2, R2, #15	     ; counter value
		LD R4, SourceMask    ; load sourcemask into R4
FinalMask	AND R4, R4, R1	     ; negate the bits that need shifting
		Loop3
			LD R4, FinalMask	; reinitialize R4 as base final mask
			AND R4, R3, R4		; check if bit at k is 1 or 0
			BRnz SKIP2  		; if bit is 1, add dest. register to result register
				ADD R0, R3, R0
			SKIP2
			ADD R3, R3, R3		; increment destination mask
			ADD R2, R2, #-1		; decrement counter
		BRp Loop3	     ; end loop
		ST R0, Result
                RET
;------------------------------------------------------------------------------
                .END
