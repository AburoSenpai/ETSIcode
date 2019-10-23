data segment
    
    ;CADENA      DB 02h,0Fh,05h,0Ah
    CADENA      DB 1,0,1,0
    PESO_HEX    DW 1000h,100h,10h,1h
    PESO_BIN    DB 8,4,2,1
    VALOR_HEX   DW 0
    VALOR_CO1   DB 0
    SIGNO_CO1   DB 0
    
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    ;Inicializar el segmento de datos
    MOV AX, SEG CADENA
    MOV DS, AX       
     
    
    MOV AH, 00h       ;Muy importante poner esa parte a 00h porque la multiplicacion deja residuos ahi                 
    MOV AL, CADENA[0]
    MUL PESO_HEX[0]       
    MOV BX, AX
    
    MOV AH, 00h  
    MOV AL, CADENA[1]
    MUL PESO_HEX[2]   ;MUY MUYIMPORTANTE sumar de 2 en dos posiciones de memoria, es un DW    
    ADD BX, AX
                            
    MOV AH, 00h  
    MOV AL, CADENA[2]
    MUL PESO_HEX[4]       
    ADD BX, AX
                            
    MOV AH, 00h  
    MOV AL, CADENA[3]
    MUL PESO_HEX[6]       
    ADD BX, AX
    
    MOV VALOR_HEX, BX
    
    ;Evaluar si es positivo o no
    MOV AL, CADENA[0]
    AND AL, AL         ;Esto es lo que se me ha ocurrido a mi para comprobarlo
    JNZ ESNEGATIVO:
    ;No es negativo luego
    JMP FINALIZAR
    
    ESNEGATIVO:       
    ;Es negativo, lo invierto y lo indico
    
    MOV AL, CADENA[1]
    NOT AL
    AND AL, 00000001b
    MOV CADENA[1], AL
    
    MOV AL, CADENA[2]
    NOT AL   
    AND AL, 00000001b
    MOV CADENA[2], AL
    
    MOV AL, CADENA[3]
    NOT AL  
    AND AL, 00000001b
    MOV CADENA[3], AL
    
    MOV SIGNO_CO1, 1
    
    FINALIZAR:
    
    MOV BX, 0
    MOV AH, 00h  
    MOV AL, CADENA[1]
    MUL PESO_BIN[1]    
    ADD BX, AX
                            
    MOV AH, 00h  
    MOV AL, CADENA[2]
    MUL PESO_BIN[2]       
    ADD BX, AX
                            
    MOV AH, 00h  
    MOV AL, CADENA[3]
    MUL PESO_BIN[3]       
    ADD BX, AX
    
    MOV VALOR_CO1, BL                
                 
                    
    ;Devolver el control al OS    
    MOV AX, 4C00h
    INT 21h  
ends

end start