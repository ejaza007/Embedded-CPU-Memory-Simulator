#include <stdio.h>
#include <stdlib.h>
#include "CPU.h"
#include "mem.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <assembly_file>\n", argv[0]);
        return 1;
    }

    initializeCPU();
    initializeMemory();


    while (1) {
        Instruction instr = fetch();
        OpCode op;
        unsigned short op1, op2;
        decode(instr, &op, &op1, &op2);
        execute(op, op1, op2);

        if (op == HALT) break;

    }


    return 0;
}
