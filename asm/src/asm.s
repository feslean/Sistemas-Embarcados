        PUBLIC median

        SECTION .text : CODE (3)
        THUMB

median:
          PUSH {R3, R4, R5, R6, R7, R8, R9, R10, R11}
          
          MOV R6,R1 ;Salva o ponteiro do vetor original em R6
          MOV R5,R0 ;Salva o tamanho do vetor em R5
          MOV R9,R2 ;Salva o ponteiro do vetor auxiliar em R9
          MOV R7,#0
          MOV R10,#0
                  
          ;Checar o tamanho desse vetor para evitar processamento desnecessário
          MOV R7,#1
          CMP R0,R7
          IT GT
          BGT M
          MOV R7,#0
          B Y2

     M:         ;Maior valor
          LDRB R3,[R6],#1
          CMP R3,R7
          IT GT
          MOVGT R7,R3 ;Salva o maior valor (M) em R7
          SUBS R5,R5,#1
          CBZ R5,A
          B M
      
    A:
 
        ;Aloca M+1 posições na pilha
    S:
          ASL R10,R7,#2
          ADDS R10,R10,#4
          MOV R5,R7
          ADDS R5,R5,#1
          SUBS R12,SP,R10
          MOV R11,R12
          MOV R6,#0
          MOV R8,#0
        
        ;Zera as M+1 posições na pilha
    LPS:
          CBZ R5,R
          STR R8,[R12,R6]
          ADDS R6,R6,#4
          SUBS R5,R5,#1
          B LPS
        
    R: 
          MOV R5,R0
          MOV R6,R1
          MOV R9,R12
        
   RC:
          ;Contagem
          CBZ R5,X1
          LDRB R8,[R6],#1 ;Salva o valor no endereço apontado por R6 em R8
          ASL R8,R8,#2 
          LDR R10,[R9,R8] ; Salva o valor apontado por R9+R8 em R10
          ADD R10,R10,#1 ; Adiciona 1 neste valor
          STR R10,[R9,R8] ; Retorna o valor anterior + 1 na posição de que foi carregado inicialmente
          SUBS R5,R5,#1
          B RC
             
             
       X1: MOV R11,#0x0
           MOV R6,R2
           ADD R7,R7,#1 ;Contando o 0 tem que ser M+1 iterações
           
       X:   ; Ordenação
          CBZ R7,Y ;M+1 Posições
          LDR R4,[R9],#4 ;R4 recebe a quantidade de cada elemento
       P: 
          CBZ R4,RESUME
          STRB R11,[R6],#1
          SUBS R4,R4,#1
          B P
  RESUME:
          ADDS R11,R11,#1
          SUBS R7,R7,#1
          B X
          
             
        Y: ;Mediana
          MOV R6,R2
        Y2:
          MOV R3,#0x0
          ASR R5,R0,#1 ;R5 é a metade de R0
          BFC R0,#1,#31 ;R0 é a própria flag de paridade
          CMP R0,#0
          ITTTE EQ
          LDRBEQ R3,[R6,R5]
          SUBEQ R6,R6,#1
          LDRBEQ R4,[R6,R5]
          LDRBNE R0,[R6,R5]
          
          CMP R3,#0
          IT EQ
          BEQ OUT
          
          ADDS R3,R3,R4
          ASR R0,R3,#1
        
       OUT:
       
       POP {R3, R4, R5, R6, R7, R8, R9, R10, R11}
       bx lr

        END