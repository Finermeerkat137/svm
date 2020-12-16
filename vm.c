#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <string.h>
#include "vm.h"
#include "utils.h"

#define VERSION 1.0
#define STACK_SIZE 2048

int registers[NUM_OF_REGISTERS];
bool running = true;

int** program = NULL;
int program_size;

bool start_vm(char* filename) {
    if (!init()) {
        return false;
    }
    if (!filename) {
        return false;
    }

    printf("Getting instructions from file %s\n", filename);

    program = read_instructions_from_file(filename);
    if (program == NULL) {
        return false;
    }
    
    bool ret = exec_vm();
    deinit();
    return ret;
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
            registers[line[1]] = registers[line[2]] + registers[line[3]];
            break;
        
        case MULT:
            registers[line[1]] = registers[line[2]] * registers[line[3]];
            break;

        case DIV:
            registers[line[1]] = registers[line[2]] / registers[line[3]];
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
            if (registers[line[1]] == registers[line[2]]) {
                registers[IP] = registers[line[3]];
            }
            break;
        }

        case XOR:
            registers[line[1]] = registers[line[2]] ^ registers[line[3]];
            break;

        case CFR:
            registers[line[1]] = registers[line[2]];
            break;

        case AND:
            registers[line[1]] = registers[line[2]] & registers[line[3]];
            break;
        
        case IFN: {
            if (registers[line[1]] != registers[line[2]]) {
                registers[IP] = registers[line[3]];
            }
            break;
        }
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

int** read_instructions_from_file(char* filename) {
    struct stat st;
    stat(filename, &st);
    program_size = st.st_size;

    int** buffer = calloc(program_size, sizeof(int*));
    
    FILE* fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        print_error("Error reading file.");
        return NULL;
    }

    char* line = NULL;
    size_t len = 0;
    int counter = 0;

    while (getline(&line, &len, fileptr) != -1) {
        int buffercounter = 0;
        char* token = strtok(line, " ");
        buffer[counter] = calloc(len, sizeof(int));

        while (token != NULL) {
            buffer[counter][buffercounter] = strtol(token, NULL, 10);
            token = strtok(NULL, " ");
            buffercounter++;
        }

        counter++;
    }

    free(line);
    fclose(fileptr);
    return buffer;
}

void deinit(void) {
    for (int i = 0; i < program_size; i++) {
        free(program[i]);
    }
    
    free(program);
}