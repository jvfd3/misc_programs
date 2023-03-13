#include <iostream>
using namespace std;

/*
  Em matemática, a série harmônica é a série infinita definida como:
  Soma(k=1)(∞) 1/K =  1/1 + 1/2 + 1/3 + ... + 1/∞
  Essa é uma série divergente, pois o valor da soma de seus termos tende ao infinito. Faça
  um programa que some o valor das parcelas dessa série em cada interação (
  primeira  iteração = 1/1,
  segunda   iteração = 1/1 + 1/2,
  terceira  iteração = 1/1 + 1/2 + 1/3
  e assim por diante),
  e pare o somatório quando o valor parcial da série for maior que um número escolhido pelo
  usuário. Mostre na tela o número de iterações necessárias para alcançar este valor.
*/

int main_q2_L() {
  int NúmeroDaIteração = 0;
  float NúmeroEscolhido = 0.0;
  float SomaHarmônica = 0.0;

  // Mensagens ao usuário separadas para facilitar alteração
  string MensagemInicial = "Escolha um número limite para série harmônica: ";
  string MensagemFinal = "O número de iterações necessárias para alcançar este valor é: ";
  
  cout << MensagemInicial;
  cin >> NúmeroEscolhido; // Obtém o número escolhido pelo usuário
  // O loop começa com o índice 1 e
  // vai ficar repetindo enquanto a soma for menor que o número escolhido pelo usuário.
  for (NúmeroDaIteração = 1; SomaHarmônica < NúmeroEscolhido ; NúmeroDaIteração ++) {
    // O numerador precisa ser com o ".0" porque ele precisa que
    // que um dos números da operação seja considerado float 
    // Para que o resultado seja float.
    SomaHarmônica += 1.0/NúmeroDaIteração;
    // cout << NúmeroDaIteração << "\t\t" <<SomaHarmônica  << '\n';
  }
  // Precisa haver a subtração por 1 porque quando o loop encerra, ele acaba somando um
  cout << MensagemFinal << NúmeroDaIteração-1;
}