#include "mem.h"
#include "CPU.h"

Memory mem[MEMORY_SIZE];

void initializeMemory() {
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        mem[i].data = 0;
    }
}

void store(unsigned short address, unsigned short value) {
    if (address < MEMORY_SIZE) {
        mem[address].data = value;
    }
}

unsigned short load(unsigned short address) {
    if (address < MEMORY_SIZE) {
        return mem[address].data;
    }
    return 0;  // Optionally handle invalid address
}
void load_assembly_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int memIndex = 0;

    while (fgets(line, sizeof(line), file) != NULL && memIndex < MEMORY_SIZE) {
        parse_and_store_instruction(line, memIndex);
        memIndex++;
    }

    fclose(file);
}


//enum OP identify_operation(const char *op) {
//    if (strcmp(op, "add") == 0) return ADD;
//    if (strcmp(op, "sub") == 0) return SUB;
//    if (strcmp(op, "neg") == 0) return NEG;
//    if (strcmp(op, "halt") == 0) return HALT;
//    return DATA;
//}

void parse_and_store_instruction(const char *line, int index) {
    char operation[20], regA[10], regB[10];
    int immediate = -1, address = -1, indexValue = -1;

    mem[index].instruction_str = strdup(line);

    if (sscanf(line, "%s %s %s %d", operation, regA, regB, &immediate) >= 1) {
       // mem[index].operation = identify_operation(operation);;
        mem[index].immediate = immediate;

    }
}




int identify_register(const char *reg) {
    if (strcmp(reg, "R0") == 0) return 0;
    if (strcmp(reg, "R1") == 0) return 1;
    return -1;
}
