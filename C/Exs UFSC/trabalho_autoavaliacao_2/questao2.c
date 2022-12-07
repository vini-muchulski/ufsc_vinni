#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tempo{
    int horas;
    int minutos;

};

int temp_minutos(struct tempo horario);

int main(){
struct tempo horario1;
int x;

horario1.horas = 3;
horario1.minutos = 28;

x = temp_minutos(horario1);

printf("%d horas e %d minutos = %d minutos totais",horario1.horas,horario1.minutos,x);


    return 0;
}

int temp_minutos(struct tempo horario){
    int total_minutos = 0;
    total_minutos = (horario.horas*60) + horario.minutos;
    return total_minutos;

}