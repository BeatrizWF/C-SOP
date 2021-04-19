#include<stdio.h>
#include <locale.h>
#include <string.h> 
#include <stdio.h>
int main(void){
    FILE *file = fopen("arquivo.txt", "r+");
    if( !file ){
        perror("Erro: ");
        getchar();
        return 1;
    }
    char codigo[100];
    printf("Digite o código do produto que deseja apagar:");
    scanf("%c",codigo);
    char indicador= codigo[0] + 1;
    char indicador2[100];
    indicador2[0] = indicador;
    char fim[]="|";
    char buffer[1204]; 
    char buffer2[1204]; 
    long int inicioLinha=0;
    long int fimLinha=0;
    inicioLinha = ftell( file ); 
    fimLinha = ftell( file ); 
    while ( fscanf(file, "%s%*c", buffer) != EOF ){
        if ( strcmp( buffer, codigo ) == 0  ){
          int TAM = strlen(buffer);
          fseek(file, inicioLinha, SEEK_SET);
          break;
        }
        inicioLinha = ftell( file );  
        inicioLinha = inicioLinha - 1;
    }

    while ( fscanf(file, "%s%*c", buffer2) != EOF ){
        if ( strcmp( buffer2,indicador2 ) == 0  ){
          fseek(file, inicioLinha, SEEK_SET);
        break;
        }else{
          if ( strcmp( buffer2,fim ) == 0  ){
            fseek(file, inicioLinha, SEEK_SET);
            fimLinha = fimLinha + 2;
            break;
          }
        }
        fimLinha = ftell( file );  
        fimLinha = fimLinha - 1;
    }
      while (inicioLinha < fimLinha) {
        inicioLinha = inicioLinha + 1;
        putc((char)' ', file);  
        }
    fclose(file);
}