#include <stdio.h>
#include <math.h>
/*  descrição do problema
  Faça um programa que leia um vetor de 400 elementos numéricos inteiros e um valor M.
  
  Após isso ele deve mostrar, na ordem inversa em que foram cadastrados,
  somente os números múltiplos de M e suas respectivas posições.
*/
int main() {
  int tamanho = 5;
  int vetor[tamanho];
  int input;
  int i;
  int M;
  int vetorResultado [tamanho];
  int resto;

  
  for (i=0; i<tamanho; i++) {
    printf("Digite um número inteiro: ");
    scanf("%d", &input);
    vetor[i]=input;
  }

  printf("\nDigite M:\n");
  scanf("%d", &M);
  

  printf("\nO valor de M é: %d\n\n", M);
  for (i=0; i<tamanho; i++) {
    vetorResultado [i] = -1;
  }
  printf("\n");

  for (i=0; i<tamanho; i++) {
    resto = vetor[i] % M;
    if (resto == 0) {
      vetorResultado [i] = vetor [i];
    }
  }
  printf("\n");
  
  int contador = 0;
  for (i=tamanho-1; i>=0; i--) {
    if (vetorResultado[i]!=-1) {
      printf("(Multiplo: %d,\tPosiçao: %d)\n", vetorResultado [i], i);
    } else {
      contador++;
    }
  }
  if (contador == tamanho) {
    printf("NÃO HÁ MÚLTIPLOS");
  }
  printf("\n");
  printf("FIM");
}