#include <iostream>
using namespace std;

/*
Escreva um programa que crie uma variável do tipo double e inicie essa variável com o valor de 1. Dentro de um loop, aumente o valor dessa variável em 1% (multiplicação por 1,01) cumulativamente a cada iteração. Quantas iterações serão necessárias para que essa variável ultrapasse o valor de 100 mil?

Opções de pergunta 5:

a) 1135 iterações
b) 1176 iterações
c) 1106 iterações
d) 1232 iterações
e) 1158 iterações  X
*/

int main_q1() {
  int NumeroLimite = 100000;
  int NumeroDaIteracao = 0;
  double porcentagem = 1.01;
  double Soma = 1.0;

  string MensagemInicial = "Escolha um número limite para série harmônica: ";
  string MensagemFinal =
      "O número de iterações necessárias para alcançar este valor é: ";

  // cout << MensagemInicial;
  // cin >> NúmeroEscolhido;

  for (NumeroDaIteracao = 1; Soma <= NumeroLimite; NumeroDaIteracao++) {
    Soma *= porcentagem;
    cout <<NumeroDaIteracao << '\t' << Soma << '\n';
  }
  cout << MensagemFinal << NumeroDaIteracao;
}