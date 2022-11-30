/*• Criar um vetor n com 10 elementos positivos do tipo int.
• Copiar valores repetidos desse vetor para um outro vetor, onde cada
valor só pode aparecer uma única vez.
• Usar função para verificar se um determinado valor aparece em um
vetor*/

#include <stdio.h>
#include <stdlib.h>

int verRep(int *vet,int tamanho, int numero);

int vetor_repeticoes(int *vet,int tamanho);


int main(){

    int const tamanho_a = 10;
    int vet_a[10]= {2,2,3,3,4,5,6,7,8,2};

    int var;
    
    var = vetor_repeticoes(vet_a, tamanho_a);



    return 0;
}

int verRep(int *vet,int tamanho, int numero){

    int i;
    int repeticoes = 0;

    for(i=0;i<tamanho; i++){
        if(vet[i]== numero){
            repeticoes++;
        }
    }

    return repeticoes;
}


int vetor_repeticoes(int *vet,int tamanho){
    int i,j;
    int var;
    int conta_repeticoes =0;
    int cont =0;
    int guarda_valores[tamanho];
    

    for(i=0;i<tamanho; i++){
        var = verRep(vet,tamanho,vet[i]);
        if (var>1){
            conta_repeticoes++;
            guarda_valores[i] = vet[i];
        }
        else{
            guarda_valores[i] = 0;
        }
    }

   
    for(int k=0;k<tamanho; k++){
        printf("%d ", guarda_valores[k]);
        
    }
    printf("\n");


     int vet_aux[conta_repeticoes];

    for(i=0;i<tamanho; i++){
       if( guarda_valores[i] !=0){
        for (j=i+1;j<tamanho;j++){
            if (guarda_valores[j]== guarda_valores[i]){
                guarda_valores[j] = 0;
            }
        } 
       }
    }
    
    printf("\n");
    for(int k=0;k<tamanho; k++){
        if( guarda_valores[k] !=0){
            vet_aux[cont] = guarda_valores[k];
            cont++;
        }
            
    }
    printf("\n");
    printf("%d", conta_repeticoes);
    printf("\n");
    printf("%d", cont);
    printf("\n");

    for(i=0;i<cont; i++){
        printf("%d ", vet_aux[i]);

    } 

}