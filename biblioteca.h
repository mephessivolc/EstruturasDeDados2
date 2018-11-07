/*
*
* Biblioteca para inserir dados numericos em uma lista de forma dinamica
*
*/

#include <stdlib.h>
#include <stdio.h>


/* definindo a estrutura dinamica */
typedef struct node {
  int info;
  struct node * next;
} Tnode;

Tnode * fila = NULL;

/* funcao de Inserir a primeira informacao */
void primeiro(int info){
  fila = (Tnode *)malloc(sizeof(Tnode));
  fila->info = info;
  fila->next = NULL;

}

/* funcao de Inserir demais informações */
void outros(int info) {
  Tnode * novo;
  Tnode * ultimo = fila;

  novo = (Tnode *)malloc(sizeof(Tnode));
  novo->info = info;
  novo->next = NULL;
  while(ultimo->next != NULL){
    ultimo = ultimo->next;
  }

  ultimo->next = novo;

}

/* funcao de inserir decidindo se for primeiro ou outro */
void inserir(int info){
  if (fila == NULL)
    primeiro(info);
  else
    outros(info);
}

/* funcao listar dados sequenciados */
void listar(){
  Tnode * indice;

  printf("\nListando\n");
  for(indice = fila; indice != NULL; indice = indice->next)
    printf("%d ", indice->info);

  printf("\n");
}
