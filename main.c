#include "vm.h"
#include "utils.h"

int main(void) {
    if (!start_vm("test_instructions")) {
        print_error("Failed to start the Virtual Machine.");
    }
}
