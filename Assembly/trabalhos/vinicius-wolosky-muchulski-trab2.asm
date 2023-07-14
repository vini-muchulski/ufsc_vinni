.org 0000h
loop: JMP loop

.org 0024h

MVI A, 1 ; zera a flag de zero para futuras reutilizacoes
ORI 1

MVI A, 0
MVI B, 0
MVI C, 0
MVI D, 0
MVI E, 0


IN 00h ; inicia a leitura do numero a partir da entrada



MOV B, A

MOV C, B
MVI E, 0

; b = dividendo
; c = divisor
; d = resto
; e = numeros de divisores


verificacao_basica: ; verifica se o numero inicial é zero ou um, pois nesse caso nao sao numeros primos
MOV A,B
CPI 0
JZ nao_primo
CPI 1
JZ nao_primo

; o processo para verificar se o numero é primo ou nao consiste em basicamente subtracoes sucessivas de o numero inicial
; pelo seus numeros anteriores. Assim sendo, o que determina se ha um divisor ou nao é o resto da divisao.
; se o resto for 0 apos a ultima subtracao que resulta em um numero menor que o divisor o numero possui algum divisor e nao é primo
; o unico valor que pode satisfazer a condicao é o 1 e o proprio numero

verificacao_de_primo:
  ; Inicializa C com B - 1, pois aqui comeca a dividir com todos os numeros menores que o numero de entrada
  MOV A, B
  DCR A
  MOV C, A

  ; Inicializar E com 0, numero de divisores
  MVI E, 0

  ; Laco para verificar se B eh divisivel por qualquer numero menor que ele

  verifica_divisores:
    ; Verificar se C eh igual a 1
    MOV A, C
    CPI 1
    JZ finaliza

    ; Calcular o resto da divisao de B por C
    MOV D, B

    calc_resto:
      MOV A, D
      SUB C
      JC menor_que_divisor
      MOV D, A
      JMP calc_resto

    menor_que_divisor:
      MVI A,0
      CMP D
      JZ incrementa_e

    ; Decrementar C e continuar verificando os proximos divisores
    DCR C
    JMP verifica_divisores

incrementa_e:
  ; Incrementar E se B for divisivel por C
  INR E

finaliza:
  ; Verificar se E eh igual a 0
  MOV A, E
  ORA A
  JZ primo


nao_primo:
  ; Armazena o valor 10h na saida 00h, indicando que é nao eh primo
  MVI  A, 16
  OUT  00h

  RET

primo:
  ; Armazena o valor 01h na saida 00h, indicando que eh primo
  MVI  A, 1
  OUT  00h

  RET