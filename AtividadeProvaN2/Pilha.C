#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAMANHO_PILHA 6

typedef struct
{
 int vetor[TAMANHO_PILHA];
 int topo;
}Pilha;

void empilha(int valor, Pilha* pilha);
int desempilha(Pilha* pilha);

void empilha(int valor, Pilha* pilha){
 if(pilha->topo < TAMANHO_PILHA){
     pilha->vetor[pilha->topo] = valor;
     pilha->topo++;
 }else{ //pilha cheia
     printf("Nao ha mais espaco na pilha");
 }
}

int desempilha(Pilha* pilha){
 if(pilha->topo > 0){
     pilha->topo--;
     printf("Numero retirado da pilha: %d\n", pilha->vetor[pilha->topo]);
 }else{ //pilha vazia
     printf("A pilha esta vazia. \n");
 }
 return pilha->vetor[pilha->topo];
}

void imprimePilha(Pilha *pilha){
 int i;

 for(i=0; i<pilha->topo; i++){
     printf("%02d\n", pilha->vetor[i]);
 }
}

int main(){
 Pilha p;
 p.topo = 0;

 empilha(64, &p); 
 empilha(25, &p); 
 empilha(12, &p); 
 empilha(22,&p); 
 empilha(11, &p); 
 empilha(9, &p); 
 printf("Pilha: \n");

 imprimePilha(&p);

 printf("Ordem de desempilhamento:\n");
 while(p.topo > 0) {
     desempilha(&p);
     sleep(1);
 }

 return 0;
}



















