#include <iostream>
using namespace std;

/*
Considerando a sequência dos números naturais {0,1,2,3,4,5,...}, escreva um
programa que calcule a soma de uma determinada quantidade de números dessa
sequência. Qual é a soma dos primeiros 331 números dessa sequência?

Opções de pergunta 1:

a) 59685
b) 64261
c) 57621
d) 54615  X
e) 66066
*/

int main_q4() {
  int Soma = 0;
  int NumeroLimite = 331;
  int NumeroDaIteracao = 0;
  for (NumeroDaIteracao = 0; NumeroDaIteracao < NumeroLimite;
       NumeroDaIteracao++) {
    Soma += NumeroDaIteracao;
    cout << NumeroDaIteracao << '\t' << Soma << '\n';
  }
}