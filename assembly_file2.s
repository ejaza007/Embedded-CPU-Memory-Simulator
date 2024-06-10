LODI R0, 0     
LODI R1, 34     
LODI R2, 1     

DO_LOOP:
ADD R0, R2, R0 

SUB R0, R1, AC  
JMPN END_LOOP   

JMP DO_LOOP     

END_LOOP:
HALT           
