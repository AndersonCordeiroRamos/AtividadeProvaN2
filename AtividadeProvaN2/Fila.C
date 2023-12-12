#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAMANHO_FILA 6

typedef struct
{
 int vetor[TAMANHO_FILA];
 int inicio;
 int fim;
}Fila;

void enfileira(int valor, Fila* fila);
int desenfileira(Fila* fila);

void enfileira(int valor, Fila* fila){
 if(fila->fim < TAMANHO_FILA){
 fila->vetor[fila->fim] = valor;
 fila->fim++;
 }else{ 
 printf("Nao ha mais espaco na fila");
 }
}

int desenfileira(Fila* fila){
 if(fila->inicio < fila->fim){
 int valor = fila->vetor[fila->inicio];
 fila->inicio++;
 printf("%d ", valor);
 return valor;
 }else{
 printf("A fila esta vazia. \n");
 return -1;
 }
}

void imprimeFila(Fila *fila){
 int i;

 for(i=fila->inicio; i<fila->fim; i++){
 printf("%02d ", fila->vetor[i]);
 }
 printf("\n");
}

int main(){
 Fila f;
 f.inicio = 0;
 f.fim = 0;

 enfileira(64, &f); 
 enfileira(25, &f); 
 enfileira(12, &f); 
 enfileira(22,&f); 
 enfileira(11, &f); 
 enfileira(9, &f); 
  
 printf("Enfileiramento: \n");

 imprimeFila(&f);

 printf("Ordem de desenfileiramento:\n");
 while(f.inicio < f.fim) {
 desenfileira(&f);
 sleep(1); 
 }
 printf("\n");

 return 0;
}

















