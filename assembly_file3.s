
LODI R0, <initial_value_of_x> 
LODI R1, 34                  
LODI R2, 15                  
LODI R3, 2                   

WHILE_LOOP_START:
SUB R0, R1, AC               
JMPN END_WHILE               


SUB R0, R2, AC               
JMPN ELSE_BLOCK              
ADD R0, R3, R0               
JMP END_IF                   

ELSE_BLOCK:
LODI R3, 1                  
ADD R0, R3, R0              
LODI R3, 2          

END_IF:
JMP WHILE_LOOP_START        

END_WHILE:
HALT                        
