#include "CPU.h"
#include "mem.h"


#define NUM_GENERAL_REGISTERS 16

unsigned short generalRegisters[NUM_GENERAL_REGISTERS];
CPU cpu;


void initializeCPU() {
    cpu.pc = 0;
    cpu.sp = 0xFFFF;
    cpu.ac = 0;
    // Initialize other registers
    for (int i = 0; i < NUM_GENERAL_REGISTERS; i++) {
        generalRegisters[i] = 0;
    }
}

Instruction fetch() {
    Instruction instr;
    instr.raw = load(cpu.pc);
    cpu.pc += 2;
    return instr;
}

void decode(Instruction instr, OpCode *op, unsigned short *op1, unsigned short *op2) {
    *op = (OpCode)(instr.raw >> 12);
    *op1 = (instr.raw >> 6) & 0x003F;
    *op2 = instr.raw & 0x003F;
}

void execute(OpCode op, unsigned short op1, unsigned short op2) {
    switch(op) {
        case ADD:
            cpu.ac = bitwiseAdd(generalRegisters[op1], generalRegisters[op2]);
            break;
            // Other cases for different instructions
        case HALT:
            exit(0);
            break;
        case SUB:
            cpu.ac = bitwiseSub(cpu.registers[op1], cpu.registers[op2]);
            break;
        case NEG:
            cpu.registers[op1] = bitwiseNeg(cpu.registers[op1]);
            break;

            case MOVA:
            cpu.registers[op1] = cpu.ac;
            break;
        case MOVR:
            cpu.registers[op2] = cpu.registers[op1];
            break;
        case LODI:
            cpu.registers[op1] = op2; // Immediate value
            break;
        case LODA:
            cpu.registers[op1] = load(op2); // Direct addressing
            break;
        case LORR:
            cpu.registers[op1] = load(cpu.registers[op2]); // Register indirect
            break;
            // Implement LORR with displacement (reg-b + pos-ind) separately
        case STOA:
            store(op2, cpu.registers[op1]); // Direct addressing
            break;
        case STOR:
            store(cpu.registers[op2], cpu.registers[op1]); // Register indirect
            break;
            // Implement STOR with displacement (reg-b + ind) separately
        case STOI:
            store(op2, op1); // Immediate value, direct addressing
            break;
        case JMP:
            cpu.pc = op1;
            break;
        case JMPZ:
            if (cpu.ac == 0) cpu.pc = op1;
            break;
        case JMPN:
            if (cpu.ac < 0) cpu.pc = op1; // Assuming negative values are represented
            break;
        case CALL:
            cpu.sp--; // Assuming stack grows downwards
            store(cpu.sp, cpu.bp);
            cpu.sp--;
            store(cpu.sp, cpu.pc);
            cpu.bp = cpu.sp;
            cpu.pc = op1;
            break;
        case RET:
            cpu.pc = load(cpu.sp);
            cpu.sp++;
            cpu.bp = load(cpu.sp);
            cpu.sp++;
            break;


    }
}

unsigned short bitwiseAdd(unsigned short a, unsigned short b) {
    unsigned short carry;
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}


unsigned short bitwiseNeg(unsigned short a) {
    return bitwiseAdd(~a, 1);
}

unsigned short bitwiseSub(unsigned short a, unsigned short b) {
    return bitwiseAdd(a, bitwiseNeg(b));
}


void displayCPU() {
    printf("CPU State:\n");
    printf("PC: %04x, SP: %04x, BP: %04x, AC: %04x\n", cpu.pc, cpu.sp, cpu.bp, cpu.ac);
    for (int i = 0; i < NUM_GENERAL_REGISTERS; i++) {
        printf("R[%d]: %04x\n", i, cpu.registers[i]);
    }
    printf("\n");
}




