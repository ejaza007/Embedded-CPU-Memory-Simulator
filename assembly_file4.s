
main:
    lodi R0, 4          
    call fun_address    
    halt               

fun_address:
    subi R0, R0, 1  
    mova R1, R0       
    lodi R0, 0         
    sub R2, R1, R0 
    jmpz end_fun        
    call fun_address    
end_fun:
    ret                 
