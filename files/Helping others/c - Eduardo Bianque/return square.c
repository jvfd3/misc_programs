#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Exercício 1.1:
Fazer uma função que retorne o quadrado de um número
*/

float quadrado(int variavel) {
  return variavel*variavel;
}

int main(){
  float variavel2;
  variavel2 = quadrado(10);
  printf("%f", variavel2);
}