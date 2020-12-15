#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "vm.h"
#include "utils.h"

#define VERSION 1.0
#define STACK_SIZE 2048

int registers[NUM_OF_REGISTERS];
bool running = true;

const int program[][4] = {
    {SET, R1, 7},
    {SET, R2, 9},
    {XOR, R1, R2, R7},
    {PRNT, R7},
    {HALT},
};

bool start_vm(char* filename) {
    if (!init()) {
        return false;
    }
    if (!filename) {
        return false;
    }

    printf("Getting instructions from file %s\n", filename);

    return exec_vm();
}

bool exec_vm(void) {

    while (running) {
        exec_instr(fetch_instr());
        registers[IP]++;
    }

    return true;
}

void exec_instr(const int* line) {
    switch(line[0]) {
        case HALT:
            running = false;
            break;

        case ADD:
            registers[line[3]] = registers[line[1]] + registers[line[2]];
            break;
        
        case MULT:
            registers[line[3]] = registers[line[1]] * registers[line[2]];
            break;

        case DIV:
            registers[line[3]] = registers[line[1]] / registers[line[2]];
            break;

        case SET:
            registers[line[1]] = line[2];
            break;

        case PRNT: {
            printf("Register %d is %d\n", line[1], registers[line[1]]);
            break;

        case NOP:
            break;

        case RJMP:
            registers[IP] += line[1];
            break;

        case IF:
            if (registers[line[1]] == line[2]) {
                registers[IP] = line[3];
            }
            break;
        }

        case XOR:
            registers[line[3]] = registers[line[2]] ^ registers[line[1]];
            break;
    }
}

const int* fetch_instr(void) {
    return program[registers[IP]];
}

bool init() {
    registers[SP] = -1;
    registers[IP] = 0;

    printf("S Virtual Machine v%.1f\n", VERSION);
    return true;
} 