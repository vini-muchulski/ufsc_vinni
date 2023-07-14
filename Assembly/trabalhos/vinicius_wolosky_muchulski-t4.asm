.define
Zero 77h
Um 44h
Dois 3Eh
Tres 6Eh
Quatro 4Dh
Cinco 6Bh
Seis 7Bh
Sete 46h
Oito 7Fh
Nove 4Fh

segUnidadePorta 05h
segDezenaPorta 04h
minUnidadePorta 03h
minDezenaPorta 02h
horaUnidadePorta 01h
horaDezenaPorta 00h

segUnidadeEndereco 30h
segDezenaEndereco 31h
minUnidadeEndereco 32h
minDezenaEndereco 33h
horaUnidadeEndereco 34h
horaDezenaEndereco 35h

; essas constantes serao usadas posteriormente no programa para acessar esses valores e endereços de forma mais legível e facil - serao usados enderecos de
; memoria para guardar os valores nos calculos para evitar alteracao desses valores ao longo do codigo

.org 24h

MVI A,77h ; inicializa os displays em zero
OUT segUnidadePorta
OUT segDezenaPorta
OUT minUnidadePorta
OUT minDezenaPorta
OUT horaUnidadePorta
OUT horaDezenaPorta

MVI A,0 ;armazena os valores 0 contidos no registrador A nos enderecos de memoria
STA segUnidadeEndereco
STA segDezenaEndereco
STA minUnidadeEndereco
STA minDezenaEndereco
STA horaUnidadeEndereco
STA horaDezenaEndereco

;O codigo começa chamando uma funcao de atraso (delay) e depois carrega o valor da unidade dos segundos da memoria para o registrador A. O valor é incrementado e armazenado de volta na memoria. 
;Se o valor for igual a 10 (0Ah em hexadecimal),ele é zerado e o processo é repetido para a dezena dos segundos, unidade e dezena dos minutos e unidade e dezena das horas. 
;O codigo verifica se o valor da hora é 24 e, se for, zera o valor da hora.

loop:
    CALL delay

    LDA segUnidadeEndereco 
    INR A 
    STA segUnidadeEndereco 
    CPI 0Ah 
    JNZ update_segUnidade 
    MVI A,0 
    STA segUnidadeEndereco 

    LDA segDezenaEndereco 
    INR A 
    STA segDezenaEndereco 
    CPI 06h 
    JNZ update_segDezena 
    MVI A,0 
    STA segDezenaEndereco 

    LDA minUnidadeEndereco 
    INR A 
    STA minUnidadeEndereco 
    CPI 0Ah 
    JNZ update_minUnidade 
    MVI A,0 
    STA minUnidadeEndereco 

    LDA minDezenaEndereco 
    INR A 
    STA minDezenaEndereco 
    CPI 06h 
    JNZ update_minDezena 
    MVI A,0 
    STA minDezenaEndereco 




    LDA horaUnidadeEndereco 
    INR A 
    STA horaUnidadeEndereco
    
    CALL verifica_2_e_4
    
    LDA horaUnidadeEndereco
    CPI 0Ah 
    JNZ update_horaUnidade 
    MVI A,0 
    STA horaUnidadeEndereco 

    LDA horaDezenaEndereco
    INR A 
    STA horaDezenaEndereco
    CPI 04h 
    JNZ update_horaDezena
    MVI A,0 
    STA horaDezenaEndereco


    
; carrega o valor da unidade das horas da memoria para o registrador A e compara com 4 (04h em hexadecimal). 
;se for diferente, a sub-rotina retorna. Caso contrario, ele carrega o valor da dezena das horas da memoria e compara com 2 (02h em hexadecimal). 
;se for igual, ele chama a sub-rotina reset_clock que provavelmente zera o valor da hora. Assim, verifica-se se o relogio chegou a 24 hrs.

verifica_2_e_4:
    LDA horaUnidadeEndereco
    CPI 04h
    JNZ subrotina_Ret
    

    LDA horaDezenaEndereco
    CPI 02h
    JZ reset_clock
  
subrotina_Ret:
	RET



	
  


     
;aqui o loop poe zero no display e seta todos os valores armazenados em 0 tbm
reset_clock:
        MVI A,77h ; seta os displays em zero
	OUT segUnidadePorta
	OUT segDezenaPorta
	OUT minUnidadePorta
	OUT minDezenaPorta
	OUT horaUnidadePorta
	OUT horaDezenaPorta

	MVI A,0 ;armazena os valores 0 contidos no registrador A nos enderecos de memoria
	STA segUnidadeEndereco
	STA segDezenaEndereco
	STA minUnidadeEndereco
	STA minDezenaEndereco
	STA horaUnidadeEndereco
	STA horaDezenaEndereco

   

	JMP loop 

;Aqui cada subrotina carrega o valor de um segmento do relogio (dezena e unidade das horas, minutos e segundos) da memoria para o registrador A e chama a funcao comparison. 
;depois disso, o valor é enviado para a porta correspondente usando a instrução OUT. 
;No final, o código salta para o inicio do loop principal.

update_horaDezena:
    LDA horaDezenaEndereco
    CALL comparison
    OUT horaDezenaPorta

update_horaUnidade:
    LDA horaUnidadeEndereco
    CALL comparison
    OUT horaUnidadePorta

update_minDezena:
    LDA minDezenaEndereco
    CALL comparison
    OUT minDezenaPorta

update_minUnidade:
    LDA minUnidadeEndereco
    CALL comparison
    OUT minUnidadePorta

update_segDezena:
    LDA segDezenaEndereco
    CALL comparison
    OUT segDezenaPorta

update_segUnidade:
    LDA segUnidadeEndereco
    CALL comparison
    OUT segUnidadePorta

JMP loop 


;essa funcao funciona vendo para qual valor no display de 7 segmentos o valor numerico guardado eh equivalente
;aqui o codigo verifica para cada valor, pulando para o digito seguinte caso o valor numerico nao seja igual ao valor do digito checado no momento

comparison:
digito0:	
		CPI 00h
	    	JNZ digito1
		MVI A, Zero
		RET
digito1:	
		CPI 01h
		JNZ digito2
		MVI A, Um
		RET
digito2: 
		CPI 02h
		JNZ digito3
		MVI A, Dois
		RET
digito3:
		CPI 03h
		JNZ digito4
		MVI A, Tres
		RET
digito4:
		CPI 04h
		JNZ digito5
		MVI A, Quatro
		RET
digito5:	
		CPI 05h
		JNZ digito6
		MVI A, Cinco
		RET
digito6:
		CPI 06h
		JNZ digito7
		MVI A, Seis
		RET
digito7:
		CPI 07h
		JNZ digito8
		MVI A, Sete
		RET
digito8:
		CPI 08h
		JNZ digito9
		MVI A, Oito
		RET
digito9:	
		CPI 09h
		JNZ digito0
		MVI A, Nove
		RET

;funcao de delay que gere atraso no codigo baseado em quantos t states cada instrucao a seguir tera, e multiplica-se o valor disso pelo periodo de cada t state, p = (1/f), f = 2 megahertz
delay:
    LXI D,0004Ah ; 10 t
delay_loop:
    DCX D ; 6 t
    MOV A,D ; 7 t
    ORA E ; 4t
    JNZ delay_loop ; 7-10 t
    RET 


; tempo total = periodo(1/f) * numero de t states
; 1 ms = 0,001 = 10**-3
; 10**-3 = (1/ 2 x 10**-6) * n
; n = 2 . 10**3

; numero de t states = 2000

;10 + x(6+10+7+4)-3 = 2000  numero t states 
;x.27 = 1993
;x =~ 74
;x em hex 4A