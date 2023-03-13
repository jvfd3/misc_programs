#include <iostream>
using namespace std;

/*
Um biólogo efetua um experimento de reprodução de um tipo específico de bactéria
em diferentes temperaturas. A cada 5 dias, as bactérias se reproduzem segundo
uma taxa que depende da temperatura "T". A taxa de reprodução, que é um
multiplicador da quantidade de bactérias, é igual a 1 + (T-30) / 100. O
experimento inicia no primeiro dia com 1000 bactérias. Escreva um programa que
calcule a quantidade total de bactérias no final do experimento, dependendo da
temperatura e da duração do experimento. Use o tipo double para o multiplicador,
a temperatura e o número de bactérias.

Considerando que o experimento foi realizado a uma temperatura de 48 graus
durante 190 dias, qual é a quantidade de bactérias no final do experimento?


Opções de pergunta 3:

a) 619443
b) 378721
c) 708802
d) 538910  X
e) 798266
*/

double calcularReproduçãoDeBactérias(double Temperatura) {
  // Foi feita uma função para poder retornar a taxa de reprodução
  double TaxaDeReproduçãoDiária = 1 + (Temperatura - 30) / 100;
  return TaxaDeReproduçãoDiária;
}
/*
Um biólogo efetua um experimento de reprodução de um tipo específico de bactéria
em diferentes temperaturas. A cada 5 dias, as bactérias se reproduzem segundo
uma taxa que depende da temperatura "T". A taxa de reprodução, que é um
multiplicador da quantidade de bactérias, é igual a 1 + (T-30) / 100. O
experimento inicia no primeiro dia com 1000 bactérias. Escreva um programa que
calcule a quantidade total de bactérias no final do experimento, dependendo da
temperatura e da duração do experimento. Use o tipo double para o multiplicador,
a temperatura e o número de bactérias.

Considerando que o experimento foi realizado a uma temperatura de 48 graus
durante 190 dias, qual é a quantidade de bactérias no final do experimento?

*/
int main_q3() { // main()
  int NúmeroDoDiaAtual = 0;
  int IntervaloDeDias = 5;
  int QuantidadeInicialDeBactérias = 1000;
  // double TemperaturaInicial = 48.0; // Giu
  double TemperaturaInicial = 50.0; // Amiga

  double QuantidadeAtualDeBactérias = QuantidadeInicialDeBactérias;
  float TemperaturaAtual = TemperaturaInicial;

  // int NúmeroEmDiasDoExperimento = 190; // Giu
  int NúmeroEmDiasDoExperimento = 180; // Amiga

  string MensagemInicial =
      "Por favor digite a duração em dias do experimento: ";
  string MensagemFinal = "A quantidade total de bactérias existentes no final "
                         "do experimento é de: ";

  cout << MensagemInicial;
  for (NúmeroDoDiaAtual = 1; NúmeroDoDiaAtual <= NúmeroEmDiasDoExperimento;
       NúmeroDoDiaAtual++) {
    if (NúmeroDoDiaAtual % IntervaloDeDias == 0) {
      // TemperaturaAtual *= 1;
      QuantidadeAtualDeBactérias *=
          calcularReproduçãoDeBactérias(TemperaturaAtual);
    }
  }
  cout << MensagemFinal << QuantidadeAtualDeBactérias;
}