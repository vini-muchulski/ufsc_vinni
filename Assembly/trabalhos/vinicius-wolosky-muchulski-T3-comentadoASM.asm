.data 4000h

; Algoritmo de Booth

.org 0000h
LXI H, 4000H
MOV C, M ;  equivalente a M
INX H
MOV B, M ;  equivalente a Q

                              

MVI E, 0 ;  equivalente a q-1
MVI D, 0 ; equivalente a A


LXI H, 4005H ; - contador de passos
MVI A,8h
MOV M,A;



VERIFICA_OVERFLOW: ; caso o valor que gera overflow for detectado inicialmente o programa ja finaliza
	MOV A, B;
	CPI 80H
	JZ fim_por_overflow;

	MOV A, C;
	CPI 80H
	JZ fim_por_overflow;




	


LOOP:

	
  ; verifica Q - o valor dos dois ultimos bits
  MOV A, B
  ANI 1h  ; Aplica AND com 00000001b (teste para o ultimo bit)
  CMP E; faz a comparacao com o q-1

  JC ADD_C_D ; 01 A+M
  JNZ SUB_C_D ; 10 A-M
  JMP CHECK_CARRY ; 11 ou 00 se nenhuma das condicoes for atendida



CHECK_CARRY:
   MOV A,D
  ANI 80H
  JZ MSB_CARRY0
  JMP MSB_CARRY1;
  	
MSB_CARRY1:
 STC ; o valor do carry é setado em 1
 JMP DESLOCA 

MSB_CARRY0:
 STC
 CMC ; independente do resultada que o carry continha antes de entrar, o valor do carry é setado em 1 e dps invertido para garantir 0
 JMP DESLOCA
  

DESLOCA:
  

 

  MOV A,D
  RAR; Desloca os bits de A para a direita, copiando o bit mais significativo para o carry
  MOV D,A

  MOV A,B
  RAR ; Desloca os bits de Q para a direita, copiando o bit mais significativo para o carry
  MOV B,A

  MOV A,E 
  RAL ; rotaciona para a esquerda para levar em conta o valor do ultimo carry
  ANI 1h ;AND com 00000001b - garantir que apenas o LSB seja válido(independente de ser 0 ou 1)
  MOV E,A;

  
 
  

  LXI H, 4005H ; - subtrai do contador de passos
  MOV A,M
  DCR A
  MOV M,A
  CPI 0;
  
  JNZ LOOP ; Se o contador de passos nao for zero, volte para o inicio do loop





FIM:
  ; O resultado final estara em D e B (parte alta e baixa do produto, respectivamente)
	
LXI H, 4002h
	MOV A,B
    	MOV M, A
	INX H

	MOV A,D
    	MOV M, A
	
	
    	HLT

ADD_C_D:  ; faz a operacao do algoritmo de 01 -> A+M
  MOV A, D
  ADD C
  MOV D, A
  JMP CHECK_CARRY ;

SUB_C_D:  ; faz a operacao do algoritmo de 10 -> A-M
  MOV A, D
  SUB C
  MOV D, A
  JMP CHECK_CARRY ;


fim_por_overflow:
	LXI H, 4002h
	MVI D,0
    	MOV M, D
	INX H
	MOV M,D
    	HLT