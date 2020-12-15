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