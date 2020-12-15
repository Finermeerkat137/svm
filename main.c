#include "vm.h"
#include "utils.h"

int main(void) {
    if (!start_vm("kfgjsd")) {
        print_error("Failed to start the Virtual Machine.");
    }
}
