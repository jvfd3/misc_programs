#include <iostream>
#include <cmath>
using namespace std;

/*
  Considere que o custo de enviar um pacote por correio expresso é de R$ 20,00
  para os 5 primeiros Kg e R$ 2,15 para cada Kg adicional ou fração acima de Kg.
  Exemplo, um pacote com 11,4 Kg custa R$ 20,00 (5 primeiros Kg) + 6 * R$ 2,15
  (6, 7, 8, 9, 10 e 11 Kg) + R$ 2,15 (fração adicional acima de 11 Kg) = R$
  35,05. Se o pacote pesar mais que 30 Kg, uma taxa adicional (fora a taxa
  normal por Kg) de R$ 20,00 deve ser adicionada ao valor final. Caso o pacote
  possua mais que 60 Kg, outra taxa adicional (fora a taxa normal por Kg) de R$
  30,00 deve ser adicionada ao valor final. Nenhum pacote com mais de 90 Kg é
  aceito para envio. Escreva um programa que receba um valor de entrada digitado
  pelo usuário contendo o peso do pacote, calcule o valor a ser pago e apresente
  esse valor na janela de saída. Caso o pacote não seja aceito, a janela de
  saída deve apresentar o texto “Pacote não aceito”.
*/

float ArredondarParaDuasCasas(float ValorASerArredondado) {
  /*
    Explicação com exemplo:
    123.456 -> Valor recebido
    12345.6 -> O valor recebido em float é multiplicado por 100
    12346.1 -> E também soma 0.5 como forma de arredondar
    12346   -> Esse valor é convertido em inteiro. A parte real é truncada
    123.46  -> Esse valor é convertido de volta ao ser dividido por 100.0
    123.46  -> O valor é retornado.
  */
  int ValorTemporário = (int)(ValorASerArredondado * 100 + .5);
  float ValorArredondado = ValorTemporário / 100.0;
  return ValorArredondado;
}

float CalcularValorDoPacote(float PesoDoPacote) {
  /*
    Esse valor funciona como chave para a condicional de ambiguidade
    Como a questão pode ser interpretada de duas formas diferentes
    ambiguidade tendo valor de 0 ativa a interpretação de que
    caso o pacote tenha mais de 60 Kg, apenas a taxa extra
    de 30 reais é adicionado (em seu devido caso); Se o
    valor for 1, então, além dos 30 reais, adiciona
    também os 20 do peso superior a 30 Kg.
  */
  int ambiguidade = 0;

  /*
    Esses valores são comparações lógicas. Eles terão valor de 0 ou 1
    Dependendo do resultado das expressões. Esses valores de 0 ou 1
    Servirão como critério de somar ou não um determinado valor
    posteriormente.
    Exemplo:
      Se "TemMaisQue5Kg" for 0 (Falso), então quando ele for calcular
      o valor por Kg acima de 5 Kg, o valor encontrado será multiplicado
      por 0, assim removendo o valor do cômputo.
  */
  int Tem5Kg = PesoDoPacote <= 5.0;
  int TemMaisQue5Kg = PesoDoPacote > 5.0;
  int TemMaisQue30Kg = PesoDoPacote > 30.0;
  int TemMaisQue60Kg = PesoDoPacote > 60.0;

  // Constantes definidas na questão
  float CustoDeEnviarUmPacotePorCorreioExpresso = 20.00;
  float TaxaPorKgOuFraçãoAdicional = 2.15;
  float TaxaFixaParaPesoMaiorQue30Kg = 20.0;
  float TaxaFixaParaPesoMaiorQue60Kg = 30.0;

  // Variáveis que serão alteradas ao longo do código
  float TaxaPorPesoEmExcesso = 0.0;
  float ValorASerPagoArredondado = 0.0;
  float ValorASerPago = 0.0;

  // - Taxa inicial
  float TaxaPadrão = CustoDeEnviarUmPacotePorCorreioExpresso;

  // - Taxa por Kg ou fração
  float PesoAlemDe5Kg = PesoDoPacote - 5.0;
  float QuantidadeDeTaxaPorPesoASerPaga = ceil(PesoAlemDe5Kg) * TemMaisQue5Kg;
  float TaxaPorPesoAlemDe5Kg =
      QuantidadeDeTaxaPorPesoASerPaga * TaxaPorKgOuFraçãoAdicional;

  // - Taxa por peso acima de 30 Kg
  float ValorTaxaParaPesoMaiorQue30Kg =
      TemMaisQue30Kg * TaxaFixaParaPesoMaiorQue30Kg;

  // - Taxa por peso acima de 60 Kg
  float ValorTaxaParaPesoMaiorQue60Kg =
      TemMaisQue60Kg * TaxaFixaParaPesoMaiorQue60Kg;

  /*
    Há ambiguidade:
    Se o pacote pesar mais que 30 Kg, uma taxa adicional (fora a taxa normal por Kg) de R$ 20,00 deve ser adicionada ao valor final.
    Caso o pacote possua mais que 60 Kg, outra taxa adicional (fora a taxa normal por Kg) de R$ 30,00 deve ser adicionada ao valor final.

    Se Pacote>30: Adiciona 20
    Se Pacote>60: Adiciona 30

    Ambiguidade: Se tiver 61 somará 30 e 20 ou apenas 30?
  */
  
  if (ambiguidade) {
    TaxaPorPesoEmExcesso +=
        ValorTaxaParaPesoMaiorQue30Kg + ValorTaxaParaPesoMaiorQue60Kg;
  } else {
    if (ValorTaxaParaPesoMaiorQue60Kg) {
      TaxaPorPesoEmExcesso += ValorTaxaParaPesoMaiorQue60Kg;
    } else {
      TaxaPorPesoEmExcesso += ValorTaxaParaPesoMaiorQue30Kg;
    }
  }
  ValorASerPago += TaxaPorPesoEmExcesso; // Taxa de grandes pesos
  ValorASerPago += TaxaPorPesoAlemDe5Kg; // Taxa por frações
  ValorASerPago += TaxaPadrão; //Taxa base

  // Arrendonda o valor para duas casas decimais de forma matemática e programática
  ValorASerPagoArredondado = ArredondarParaDuasCasas(ValorASerPago);
  return ValorASerPagoArredondado;
}

int main_q5_L() {
  // Limite definido na questão
  float PesoLimite = 90.0;

  // Variáveis que serão atribuídas futuramente
  float PesoDoPacote = 3.0; // Pelo usuário
  float ValorDoPacote; // Pela função de cálculo de valor
  
  // Mensagens que poderão ser mostradas ao usuário
  string MensagemInicial = "Por favor digite o peso do pacote (em Kg): ";
  string MensagemFinalComValor = "O valor a ser pago é de: R$ ";
  string MensagemFinalAlternativa = "Pacote não aceito";

  cout << MensagemInicial;
  cin >> PesoDoPacote;

  // Se o "PesoDoPacote" for maior do que o PesoLimite estipulado
  // Será mostrada a mensagem de "Pacote não aceito"
  // Senão, o valor do pacote é calculado baseado em seu peso
  // E então seu valor é informado ao usuário
  if (PesoDoPacote > PesoLimite) {
    cout << MensagemFinalAlternativa;
  } else {
    ValorDoPacote = CalcularValorDoPacote(PesoDoPacote);
    cout << MensagemFinalComValor << ValorDoPacote;
  }
}