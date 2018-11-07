#include "biblioteca.h"
#include <time.h>

#define high 100
#define low 0


void bubleSort(Tnode * primeiro) {
    Tnode * atual, * prox, * ultimo;
    int temp, passos = 0;

    for (ultimo = primeiro; ultimo != NULL; ultimo = ultimo->next){
      for (atual = primeiro; atual->next != NULL; atual=atual->next){
        passos++;

        prox = atual->next;
        if (atual->info > prox->info){
          temp = atual->info;
          atual->info = prox->info;
          prox->info = temp;

        }
      }
    }
}

void bubleSortM(Tnode * primeiro) { // bubleSort Melhorado
    Tnode * atual, * prox, * ultimo, * fim  = NULL;
    int temp, passos = 0;
    _Bool estaoOrdenados;

    for (ultimo = primeiro; ultimo->next != NULL; ultimo = ultimo->next){
      estaoOrdenados = 1;
      for (atual = primeiro; atual->next != fim; atual=atual->next){
        passos++;

        prox = atual->next;
        if (atual->info > prox->info){
          estaoOrdenados = 0;
          temp = atual->info;
          atual->info = prox->info;
          prox->info = temp;

        }
      }
      fim = atual;
      if(estaoOrdenados == 1)
        break;
    }
}

void main() {
  int info, i, k;
  double r;
  srand(time(NULL));

  for(i=0; i<=5; i++){
    r = (double) rand () / ((double) RAND_MAX + 1);
    k = r * (high - low + 1);
    inserir(k);
  }

  listar();

  bubleSortM(fila);

  listar();
}
