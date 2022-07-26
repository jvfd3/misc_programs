#include <stdio.h>
#include <stdlib.h>
/*
  Escreva um programa na Linguagem C para preencher 2 matrizes A10x10 e B10x10 de inteiros.

  Após o preenchimento o programa deve imprimir:

  - A diagonal secundária de ambas matrizes

  - Se A e B são simétricas (Uma matriz é chamada simétrica quando, para qualquer elemento da matriz A, a igualdade aij = aji é verdadeira). Ex:
*/

void printMatriz(int tamanho, int** matriz) {
  int i,j;
  for (i = 0; i<tamanho; i++) {
    for (j = 0; j<tamanho; j++) {
      printf("[%d]\t", matriz[i][j]);
    }
    printf("\n");
  }
}

int** criarMatriz(int tamanho) {
  int i, j;
  int** matriz = (int**) malloc (tamanho * sizeof(int));
  for (i = 0; i<tamanho; i++) {
    int* VetorColuna = (int*) malloc (tamanho * sizeof(int));
    matriz[i] = VetorColuna;
  }
  return matriz;
}

void preencherMatriz (int tamanho, int** matriz) {
  int i, j;
  for (i = 0; i<tamanho; i++) {
    for (j = 0; j<tamanho; j++) {
      // printf("Digite o valor de Matriz[%d][%d]:\n", i, j);
      // scanf("%d", &matriz[i][j]);
      // matriz[i][j] = 2 + 2*i + j;
      matriz[i][j] = i + j;
    }
  }
}

void ObterDiagonalSecundaria(int tamanho, int** matriz) {
  printf("\n");
  int vetor [tamanho];

  int i, j = 0;
  for (i = 0; i<tamanho; i++) {
    vetor [i] = matriz[i][tamanho-1-j];
    j++;
  }

  printf("Diagonal Secundaria: ");
  for (i = 0; i<tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void conferirSimetrica (int tamanho, int** matriz) {
  printMatriz(tamanho, matriz);

  int objetivo = tamanho*tamanho;
  int contagemDeIgualdade = 0;
  int ehSimetrica = 0;
  
  int i, j;
  for (i = 0; i<tamanho; i++) {
    for (j = 0; j<tamanho; j++) { 
      if (matriz[i][j] == matriz[j][i]) {
        contagemDeIgualdade ++;
      }
    }
  }

  if (contagemDeIgualdade == objetivo) {
    ehSimetrica = 1;
  }

  printf("A matriz é Simétrica?\t");
  if (ehSimetrica) {
    printf("Sim");
  } else {
    printf("Não");
  }

}

int main() {
  int tamanho = 10;

  int** matrizA = criarMatriz(tamanho);
  int** matrizB = criarMatriz(tamanho);

  preencherMatriz(tamanho, matrizA);
  preencherMatriz(tamanho, matrizB);

  ObterDiagonalSecundaria(tamanho, matrizA);
  ObterDiagonalSecundaria(tamanho, matrizB);
  
  conferirSimetrica(tamanho, matrizA);
  conferirSimetrica(tamanho, matrizB);
}