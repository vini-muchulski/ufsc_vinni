.org 100h
mvi A, 05h ;carrega o acumulador com o valor 05h
mvi C,02h ;carrega o registrador C com o valor 02h
add C ;adiciona o conte�do de C ao conte�do do acumulador. A = 05h + 02h = 07h
adi 10h ;adiciona 10h ao conte�do de A. A = 07h + 10h = 17h
adc C ; adiciona o conte�do de C ao pr�prio conte�do de A, incluindo o valor de carry.
; A = 17h + 02h + 0 = 19h. O valor de carry era zero.
aci 03h ; adiciona 03h e cy ao conte�do do acumulador. A = 19h + 03h = 1Ch