#pragma once
#include <stdbool.h>

typedef enum {
    HALT, // End program
    ADD,  // Add values from 2 registers, and store in 3rd. ADD R1, R2, R3
    MULT, // Above but for multiply
    DIV,  // Above but for divide
    SET,  // Set register to value. SET R1 8
    PRNT, // Dump values of registers
    NOP,  // Do nothing and increment IP.
    RJMP, // Increment ip by operand
} instruction_set;

typedef enum { // R1 - 7 : general purpose registers
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    SP,
    IP,
    NUM_OF_REGISTERS,
} register_types;

bool start_vm(char* input_file);
bool init();
const int* fetch_instr(void);
bool exec_vm(void);
void exec_instr(const int* line);