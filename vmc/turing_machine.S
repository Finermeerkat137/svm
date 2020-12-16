; Set registers to "states" 
SET R2 2
SET R4 4
; Store line numbers
SET R5 6
SET R6 10
; Set state to 2 and begin execution of Turing Machine
SET R7 2
IF R7 R2 R5
IF R7 R4 R6
NOP
PRNT R7
SET R7 4
; Jump back to beginning
RJMP -6
NOP
PRNT R7
SET R7 2
RJMP -5
HALT