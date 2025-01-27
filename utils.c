#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void print_error(char *message) {
        fflush(stdout);
        fprintf(stderr, "\033[0;31mERROR: %s\n\033[0m", message);
}

void print_success(char *message) {
        fflush(stdout);
        printf("\033[32mSUCCESS: %s\n\033[0m", message);
        fflush(stdout);
}

void print_warning(char *message) {
        fflush(stdout);
        fprintf(stderr, "\033[33mWARNING: %s\n\033[0m", message);
        fflush(stdout);
}

bool does_file_exist(char* filename) {
        if (access(filename, R_OK) == -1) {
                return false;
        }

        return true;
}
