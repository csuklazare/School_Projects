; Recitation 10
; Author: <name>
; Date:   <date>
; Email:  <email>
; Class:  CS270
; Description: copies least significant byte to most significant
;--------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000

                JSR copy           ; call function
                HALT

; Parameter and return value
; Try changing Param's .BLKW 1 to .FILL xNNNN where N is a hexadecimal value or #NNNN
; where N is a decimal value, this can save you time by not having to set these 
; values in the simulator every time you run your code. This is the only change 
; you should make to this section.
Param           .BLKW 1              ; space to specify parameter
Result          .BLKW 1              ; space to store result

; Constants, the use of One and Eight is optional
One             .FILL #1             ; the number 1   
Eight           .FILL #8             ; the number 8
Mask            .FILL x00ff          ; mask top bits

; End reserved section: do not change ANYTHING in reserved section!
;--------------------------------------------------------------------------
copy         LD R0,Param          ; load pattern

                                     ; your code here
                ADD R1, R0, #0       ; make a copy of register 0 to register 1
                LD R2, Mask          ; load mask into register 2
                AND R1, R2, R1       ; use the mask to clear bits 15:8 in the result
                ADD R2, R3, R1       ; initialize register 2 to 1, source mask
                ADD R3, R3, R1       ; initialize register 3 to 1, dest. mask
                ADD R4, R4, #8       ; initialize register 4 to #8, this is counter
                Loop1                    ; loop to shift register 3 left by 8 bits
                        ADD R3, R3, R3
                        ADD R4, R4, #-1
                        BRp Loop1
                ST R1,Result             ; store result
                ADD R4, R4, #8           ; initialize register 4 to #8 again
                Loop2                    ; second loop
			AND R5, R2, R0   ; checks if bit in source mask is in param
			BRnz SKIP	 ; if statement
                        	ADD R1, R1, R3   ; if so, add dest. mask to result
			        ADD R2, R2, R2   ; shift source mask left
			        ADD R3, R3, R3   ; shift dest. mask left
				BRnzp END
			SKIP
                        ADD R4, R4, #-1  ; decrement counter
                        BRp Loop2
			END
		ST R1, Result               
                RET
;--------------------------------------------------------------------------
               .END

