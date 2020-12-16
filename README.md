# virtual machine thingy

It's turing complete too :)

The destination register is the first one, and the resulting are the arguments.

|Number|Instruction|Description|Examples
-------|-----------|-----------|--------|
|0|HALT|Stop execution|HALT|
|1|ADD| Add values in R1 specified registers | ADD R1 R2 R3 |
|2|MULT| Multiply values in specified registers | MULT R1 R2 R2 |
|3|DIV| Divide values in specified registers | DIV R1 R2 R3 |
|4|SET| Set register to operand | SET R1 954 |
|5|PRNT| Print value of register to stdout | PRNT R1 |
|6|NOP| Do nothing | NOP |
|7|RJMP| Jump to instruction relative to current | RJMP -3 (will jump 3 instructions back)|
|8|IF| If the specified register equals the register in operand, set IP to second operand | IF R1 R4 R5 (if R1 equals R4 set IP to R5)
|9|XOR| XOR the values in specified registers and output to first specified register | XOR R1 R2 R7 |
|10|CFR| Copy from register to register | CFR R3 R5 |
|11|AND| Execute an AND bitwise operation on the values in two registers, and store in the first | AND R5 R1 R1|
|12|IFN| If the specified register does not equal the register in operand, set IP to second operand | IFN R1 R4 R5 (if R1 does not equal R4 set IP to R5)
|13|PUSH| Push number in register to stack| PUSH R1
|14|POP| Pop number in stack into register | POP R1

NOTE: To compile, first write the correct ASM, then call `vmasm` on the file to convert it to instructions. Then, call `vm` on the instruction file.
