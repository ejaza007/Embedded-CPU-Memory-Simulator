; Assuming R0 is used for variable x, R1 for the constant 34, and R2 for constant 1

LODI R0, 5      ; Initialize x to 5 (change to 35 for the second test case)
LODI R1, 34     ; Load immediate value 34 into R1 for comparison
LODI R2, 1      ; Load immediate value 1 into R2 for incrementing/decrementing

SUB R0, R1, AC  ; AC = R0 - R1 (x - 34)
JMPN ELSE_BLOCK ; If AC is negative (x >= 34), jump to ELSE_BLOCK
ADD R0, R2, R0  ; x++ (Executes if x < 34)
JMP END_IF      ; Jump to end of the if-else block

ELSE_BLOCK:
SUB R0, R2, R0  ; x-- (Executes if x >= 34)

END_IF:
HALT            ; Stop the program
