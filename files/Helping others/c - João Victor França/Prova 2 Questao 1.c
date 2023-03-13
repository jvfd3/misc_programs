#include <stdio.h>
#include <stdlib.h>

int* RelatorioCurtidas() {
  int* vetor = (int*) malloc (7* sizeof(int));
  int i;
  for (i=0; i<7; i++) {
    vetor[i] = rand()%100;
    // scanf("%d", &vetor[i]);
  }
  return vetor;
}

float* RelatorioTempoMedio() {
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
void MediaCurtidas(int* vetor) {
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
void DiasRelatorioComTempoMaiorQue (float* vetor, int meta) {
  int i;
  int diasnaMeta=0;
  for (i=0; i<7; i++) {
    if (vetor[i]>meta) {
      diasnaMeta++;
    }
  }
  printf("\n%d\n\n", diasnaMeta);
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
  int* vetorCurtidas = RelatorioCurtidas();
  float* vetorTempo = RelatorioTempoMedio();
  int keepLooping = 1;
  while (keepLooping) {
    switch(getChoice()) {
      case 1: {
        MediaCurtidas(vetorCurtidas);
      };
      break;
      case 2: {
        int meta;
        printf("Digite a meta de tempo\t");
        scanf("%d", &meta);
        DiasRelatorioComTempoMaiorQue(vetorTempo, meta);
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