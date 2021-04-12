#include <stdio.h>
int main(void) {
  char buffer[1000];
  FILE * produtosLerP;
  size_t nread;

  produtosLerP = fopen("./produtos.txt", "r");

  if(produtosLerP == NULL) {
      printf("Erro! Arquivo.txt não encontrado.");
      return 0;
  }

  while ((nread = fread(buffer, 1, sizeof buffer, produtosLerP)) > 0) {
      printf("%s", buffer);
      printf( "\n");
  }


  fclose(produtosLerP);    
  return 0;
}