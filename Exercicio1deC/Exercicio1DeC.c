#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

float* alocarArrayFloatMemoria(int numeroelementos) {
    float **p;
    /* p para Ponteiro para vetor, Contadores, numeroelementos para determinar qtd de elementos do vetor*/
    int b = 1;
    int cont;
    if (numeroelementos < 1) {
      printf ("Erro. \n");
      return NULL;
    }
    p = (float **) calloc (numeroelementos, sizeof(float *));
    
    if (p == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return NULL;
    }
    for ( cont = 0; cont < numeroelementos; cont++ ) {
        p[cont] = (float*) calloc(b, sizeof(float));
        if (p == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return NULL;
        }
    }
    return *p;
}
  /*Liberar matriz */
  /*Ponteiro disponivel*/
int * liberoMatrizInteiros (int a, int b, int * c)
{
  if (c == NULL) return (NULL);
  free(c);      
  return (NULL);
}

int main(void) {
  int qtdturmaalunos1 = 0;
  int qtdturmaalunos2 = 0;
  float *notasdaturma1;
  float *notasdaturma2;
  float mediaturma1 = 0;
  float mediaturma2 = 0;
  printf("\nQuantos alunos contém na primeira turma? ");
  scanf("%d", &qtdturmaalunos1);
  notasdaturma1 = alocarArrayFloatMemoria(qtdturmaalunos1);


  /* Primeira Turma */
  for (int cont = 0; cont < qtdturmaalunos1; cont++){
    printf("\nDigite a nota do %d º aluno : ", cont + 1);
    scanf("%f", &notasdaturma1[cont]);
  }

  for(int cont2 = 0; cont2 < qtdturmaalunos1; cont2++){
    mediaturma1 = mediaturma1 + notasdaturma1[cont2];
  }
  mediaturma1 = mediaturma1 / qtdturmaalunos1;
  printf("\nA média da 1ª turma foi %.1f \n", mediaturma1);
  free(notasdaturma1);


  /* Segunda Turma */
  printf("\nQuantos alunos contém na segunda turma? ");
  scanf("%d", &qtdturmaalunos2);
  notasdaturma2 = alocarArrayFloatMemoria(qtdturmaalunos2);


  for(int cont = 0; cont < qtdturmaalunos2; cont++){
    printf("\nDigite a nota do %d º aluno : ", cont + 1);
    scanf("%f", &notasdaturma2[cont]);
    }

  for(int cont2 = 0; cont2 < qtdturmaalunos2; cont2++){
    mediaturma2 = mediaturma2 + notasdaturma2[cont2];
  }


  mediaturma2 = mediaturma2 / qtdturmaalunos2;
  printf("\nA média da 2ª turma foi %.1f", mediaturma2);
  free(notasdaturma2);

  return 0;
}