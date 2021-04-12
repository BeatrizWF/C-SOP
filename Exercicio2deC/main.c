#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int qtdprodutoscadastrar = 0;
  int codigo = 0;
  double valor;
  int tamanhodotexto = 1000;
  char buffer[tamanhodotexto];
  char nome[tamanhodotexto];
  char *linha[tamanhodotexto];
  FILE *produtosCriarP;
  FILE *produtosLerP;
  FILE *produtosP;

  produtosLerP = fopen("./produtos.txt", "r");

  if(produtosLerP == NULL) {
      produtosLerP = fopen("./produtos.txt", "w");
      produtosLerP = fopen("./produtos.txt", "r");
  }

  produtosP = fopen("./produtos.txt", "a");

  if(produtosP == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    exit(EXIT_FAILURE);
  }
  printf("Digite a quantidade de produtos que deseja cadastrar: \n");
  scanf("%i", &qtdprodutoscadastrar);

  for(int cont = 0; cont < qtdprodutoscadastrar; cont++) {
    printf("\nDigite o código %dº do produto: \n",cont + 1);
    scanf("%i", &codigo);
    fprintf(produtosP, "%d",codigo);
    printf("\nDigite o nome do produto: \n");
    scanf("%s", nome);
    fprintf(produtosP, "%s", "_");
    fprintf(produtosP, "%s", nome);
    printf("\nDigite o valor do produto: \n");
    scanf("%lf", &valor);
    fprintf(produtosP, "%s", "_");
    fprintf(produtosP, "%.2f", valor);
    fprintf(produtosP, "%s", "\n");
    }

    fclose(produtosP);

    printf("\nArquivo criado e preenchido. \n");

  return 0;
}