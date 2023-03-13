#include <iostream>
using namespace std;

/*
  Um biólogo efetua um experimento de medida da taxa de reprodução assexuada de
  um tipo específico de bactéria em diferentes temperaturas. A taxa de reprodução
  diária (multiplicador) das bactérias a uma temperatura “T” é igual a 1 + (T-40)
  / 100. O biólogo inicia o primeiro dia de testes com 1000 bactérias e uma
  temperatura T = 45. No início de cada dia múltiplo de 2, a temperatura aumenta
  em 0,3°C. Escreva um programa que receba do usuário a duração em dias do
  experimento e apresente na janela do programa a quantidade total de bactérias
  existentes no final do experimento.
*/

float calcularReproduçãoDeBactérias(float Temperatura) {
  // Foi feita uma função para poder retornar a taxa de reprodução
  float TaxaDeReproduçãoDiária = 1 + (Temperatura - 40) / 100;
  return TaxaDeReproduçãoDiária;
}

int main_q4_L() { // main()
  int NúmeroDoDiaAtual = 0;
  // Alguns valores definidos como fixos na questão podem ser modificados caso deseje
  int QuantidadeInicialDeBactérias = 1000;
  float TemperaturaInicial = 45.0;

  // Os valores "atuais" são aqueles sobre os quais já se espera que sofram
  // variação ao longo da execução do programa
  int QuantidadeAtualDeBactérias = QuantidadeInicialDeBactérias;
  float TemperaturaAtual = TemperaturaInicial;

  // Número que será solicitado ao usuário.
  int NúmeroEmDiasDoExperimento = 0;

  // Mensagens ao usuário separadas para facilitar alteração
  string MensagemInicial =
      "Por favor digite a duração em dias do experimento: ";
  string MensagemFinal = "A quantidade total de bactérias existentes no final "
                         "do experimento é de: ";

  cout << MensagemInicial;
  cin >> NúmeroEmDiasDoExperimento;

  // O loop ocorrerá enquanto o índice ("NúmeroDoDiaAtual") for menor ou igual ao Número em dias do experimento. 
  for (NúmeroDoDiaAtual = 1; NúmeroDoDiaAtual <= NúmeroEmDiasDoExperimento;
       NúmeroDoDiaAtual++) {
    // A porcentagem funciona para retornar o resto da divisão por 2
    // Se o "NúmeroDoDiaAtual" for par, a divisão por dois vai ter resto zero
    // Se der resto zero, será "==" a 0, então a condição para o if é verdadeira
    // Então, no início dos dias pares, a temperatura aumenta em 0.3
    if (NúmeroDoDiaAtual % 2 == 0) {
      TemperaturaAtual += 0.3;
    }
    // A operação "*=" atribui à variável o seu próprio valor múltiplicado ao valor
    // da direita
    QuantidadeAtualDeBactérias *= calcularReproduçãoDeBactérias(TemperaturaAtual);
  }
  cout << MensagemFinal << QuantidadeAtualDeBactérias;
}