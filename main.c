#include "vm.h"
#include "utils.h"

#define error_vm(x) print_error("Failed to start the Virtual Machine."); return x

int main(int argc, char** argv, char** envp) {
    if (argc < 2) {
        print_error("Insufficient arguments.");
        error_vm(1);
    }

    if (!start_vm(argv[1])) {
        error_vm(2);
    }
}
