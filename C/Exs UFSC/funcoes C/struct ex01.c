#include <stdio.h>

typedef struct dma{

int hora;
int minuto;

}horario;

horario minutos_p_horas(int x){

    horario horas;

    horas.hora = x/60;
    horas.minuto = x%60;

    return horas;
}

int horas_p_minutos(horario y){

    int minutos_totais;

    minutos_totais = y.hora*60+ y.minuto;

    return minutos_totais;
}


int main(){
horario x,v;
int w;
int h;

w = 191;
x = minutos_p_horas(w);

printf("horas %d  - minutos %d \n", x.hora, x.minuto);


v.hora = 4;
v.minuto=0;

h = horas_p_minutos(v);

printf("minutos %d ", h);

return 0;
}



