#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#define NUM_GENERAL_REGISTERS 16


typedef struct {
    unsigned short pc; // Program Counter
    unsigned short sp; // Stack Pointer
    unsigned short bp; // Base Pointer
    unsigned short ir; // Instruction Register
    unsigned short ac; // Accumulator
    unsigned short registers[NUM_GENERAL_REGISTERS];
} CPU;

typedef struct {
    unsigned short raw;
} Instruction;

typedef enum {
    ADD, SUB, NEG,
    MOVA, MOVR, LODI, LODA, LORR, STOA, STOR, STOI,
    JMP, JMPZ, JMPN, HALT, CALL, RET,

} OpCode;

// Function prototypes
void initializeCPU();
Instruction fetch();
void decode(Instruction instr, OpCode *op, unsigned short *op1, unsigned short *op2);
void execute(OpCode op, unsigned short op1, unsigned short op2);
unsigned short bitwiseAdd(unsigned short a, unsigned short b);
unsigned short bitwiseSub(unsigned short a, unsigned short b);
unsigned short bitwiseNeg(unsigned short a);



#endif // CPU_H
