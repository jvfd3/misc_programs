#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Opcoes(){
    int escolha_L=0;
    do  {
        printf("Escolha entre os sistemas de votação:\n");
        printf("0) Terminar\n");
        printf("1) O mais votado\n");
        printf("2) O mais votado com segundo turno\n");
        printf("3) Versus (um ou outro)\n");
        printf("4) Classificacao entre ótimo(5), Muito bom(4), bom(3), satisfatorio(2), ruim(1), rejeitável(0)\n");
        scanf("%d", &escolha_L);
    }   while (escolha_L>0 && escolha_L<5);
    return escolha_L;
}

int main (void){
 //   setlocale(LC_ALL,"portuguese");

 //   int voto[5];
    int escolha;
//    int candidatos=2    ;
    /*
    
    */

   escolha=Opcoes();
    printf("Escolha: %d", escolha);
}