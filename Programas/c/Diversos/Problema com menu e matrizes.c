#include <stdio.h>
#include <stdlib.h>
/*
  Com o Black Friday chegando, uma loja virtual do ramo de equipamentos agrários necessita de um programa que gere resultados rápidos a partir de um relatório que ele recebe da rede social. Este relatório de 7 dias é referente a um post realizado e é composto de 2 listas: uma com a quantidade de curtidas e outra com o tempo médio (em segundos e que pode ser fracionado) do usuário visitando aquele post.

  Crie um programa que permita cadastrar estes valores e exiba um menu onde ele possa conhecer:
  - Qual a média de curtidas desse post
  - A quantidade de dias que média de tempo de visualização foi acima de X segundos (valor este que deve ser informado pelo usuário)
  - Qual período da semana (meio ou fim de semana) se obteve a maior média do tempo de visitação (meio de semana: 1-5, fim de semana: 6-7)
  - Sair
  O programa só deve ser encerrado quando a opção de ‘sair’ for selecionada.
*/

int* obterRelatorioCurtidas() {
  //RETORNAR VETOR COM INFORMAÇÕES DE CURTIDAS
  int* vetor = (int*) malloc (7* sizeof(int));
  int i;
  for (i=0; i<7; i++) {
    vetor[i] = rand()%100;
    // scanf("%d", &vetor[i]);
  }
  return vetor;
}

float* obterRelatorioTempoMedio() {
  //RETORNAR VETOR COM INFORMAÇÕES DE TEMPO 
  float* vetor = (float*) malloc (7* sizeof(float));
  int i;
  int parteInteira;
  float parteFloat;
  for (i=0; i<7; i++) {
    parteInteira = rand()%100;
    parteFloat = (rand()%100)/100;
    vetor[i] = parteInteira + parteFloat;
    // scanf("%f", &vetor[i]);
  }
  return vetor;
}

void CalcularMediaCurtidas(int* vetor) {
  //- Qual a média de curtidas desse post
  int i;
  int soma = 0;
  int count = 0;
  for (i=0; i<7; i++) {
    soma += vetor[i];
    count ++;
  }
  float media = soma/count;
  printf("\nMédia: %.2f\n\n", media);
}

void diasDoRelatorioComTempoMaiorQue (float* vetor, int meta) {
  
  int i;
  int diasDentroDaMeta=0;
  for (i=0; i<7; i++) {
    if (vetor[i]>meta) {
      diasDentroDaMeta++;
    }
  }
  printf("\n%d\n\n", diasDentroDaMeta);
}

void PeriodoComMaiorMedia(float* vetor) {
  float tempoMeioDaSemana=0, tempoFimDeSemana=0;
  float mediaMeioDaSemana,   mediaFimDeSemana;
  int   countMeioDaSemana=0, countFimDeSemana=0;
  int i;
  for (i=0; i<5; i++) {
    tempoMeioDaSemana+=vetor[i];
    countMeioDaSemana++;
  }
  for (i=0; i<2; i++) {
    tempoFimDeSemana+=vetor[5+i];
    countFimDeSemana++;
  }
  mediaMeioDaSemana = tempoMeioDaSemana/countMeioDaSemana;
  mediaFimDeSemana = tempoFimDeSemana/countFimDeSemana;

  printf("Período com maior média de tempo: ");
  if (mediaMeioDaSemana > mediaFimDeSemana) {
    printf("Meio Da Semana.\n");
  } else {
    printf("Fim De Semana.\n");
  }
}

int getChoice () {
  int choice;
  printf("Digite o codigo correspondente:\n\n");
  printf("1) Media de curtidas\n");
  printf("2) Quantidade de dias com media maior que\n");
  printf("3) Periodo com maior média\n");
  printf("4) Sair\n");
  scanf("%d", &choice);
  return choice;
}

void menu() {
  int* vetorCurtidas = obterRelatorioCurtidas();
  float* vetorTempo = obterRelatorioTempoMedio();
  int keepLooping = 1;
  while (keepLooping) {
    switch(getChoice()) {
      case 1: {
        CalcularMediaCurtidas(vetorCurtidas);
      };
      break;
      case 2: {
        int meta;
        printf("Digite a meta de tempo\t");
        scanf("%d", &meta);
        diasDoRelatorioComTempoMaiorQue(vetorTempo, meta);
      }; break;
      case 3: {
        PeriodoComMaiorMedia(vetorTempo);
      }; break;
      case 4: {
        keepLooping = 0;
      }; break;
    }
  }
}

int main() {
  menu();
}