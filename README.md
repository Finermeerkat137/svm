# virtual machine thingy

|Number|Instruction|Description|Examples
-------|-----------|-----------|--------|
|0|HALT|Stop execution|HALT|
|1|ADD| Add values in specified registers | ADD R1 R2 R3 |
|2|MULT| Multiply values in specified registers | MULT R1 R2 R2 |
|3|DIV| Divide values in specified registers | DIV R1 R2 R3 |
|4|SET| Set register to operand | SET R1 954 |
|5|PRNT| Print value of register to stdout | PRNT R1 |
|6|NOP| Do nothing | NOP |
|7|RJMP| Jump to instruction relative to current | RJMP -3 (will jump 3 instructions back)|
|8|IF| If the specified register equals the operand, set IP to second operand | IF R1 8 9 (if R1 equals 8 set IP to 9)
|9|XOR| XOR the values in specified registers and output to last specified register | XOR R1 R2 R7 |
|10|CFR| Copy from register to register | CFR R3 R5 |