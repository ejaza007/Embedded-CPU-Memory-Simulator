#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 65536

typedef struct {
    int reg_a;
    int reg_b;
    int immediate;
    int address;
    int index;
    char *instruction_str;
    int data;
    int operation;
} Memory;

// Function prototypes
void initializeMemory();
void store(unsigned short address, unsigned short value);
unsigned short load(unsigned short address);
void load_assembly_file(const char *filename);
void parse_and_store_instruction(const char *line, int index);
enum OP identify_operation(const char *op);

#endif // MEM_H
